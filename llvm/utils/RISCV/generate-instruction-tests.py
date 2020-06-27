#!/usr/bin/env python3
import re

class Field(object):

  def get_memonic():
    """
    return the field memonic, if this field
    has't a memonic, return empyt string
    """
    raise NotImplementedError

  def get_encoding():
    """
    return the field encoding
    """
    raise NotImplementedError

  @staticmethod
  def is_fixed():
    """
    return true if this field is fixed in the 
    instruction format. Otherwise false
    """
    raise NotImplementedError
  
  @staticmethod
  def depend_on_other_field():
    """
    return true if this field is depend on the other field
    for example: the mew depend on the width field
    """
    raise NotImplementedError

class Width(Field):
  """
  represent a width field
  """

  pattern = re.compile("^width$")
  widths = [8, 16, 32, 64, 128, 256, 512, 1024]
  encoding = ["000", "101", "110", "111", "000", "101", "110", "111"]

  def __init__(self, index):
    self.index = index
    self.extend = index > 3

  @staticmethod
  def make(index):
    return Width(index)

  @staticmethod
  def get_indices():
    return [i for i in range(len(Width.widths))][4:]

  def get_memonic(self):
    return str(self.widths[self.index])

  def get_encoding(self):
    return self.encoding[self.index]

  @staticmethod
  def is_fixed():
    return False

  @staticmethod
  def depend_on_other_field():
    return False

class Mew(Field):
  """
  represent the mew field
  """
  pattern = re.compile("^mew$")
  
  def make(text):
    return Mew()

  def get_memonic(self):
    return ""

  def get_encoding(self, instruction):
    # this method is not very good
    for field in instruction:
      if isinstance(field, Width):
        return "1" if field.extend else "0"
    raise("unreachable!")

  @staticmethod
  def depend_on_other_field():
    return True

  @staticmethod
  def is_fixed():
    return True

class Vm(Field):
  """
  represent the vm field
  """
  pattern = re.compile("^vm$")
  all_mask = ["", ", v0.t"]

  def __init__(self, index):
    self.index = index

  @staticmethod
  def make(index):
    return Vm(index)

  @staticmethod
  def get_indices():
    return [i for i in range(len(Vm.all_mask))]

  def get_memonic(self):
    return self.all_mask[self.index]

  def get_encoding(self):
    return "0" if self.index else "1"

  @staticmethod
  def is_fixed():
    return False

  @staticmethod
  def depend_on_other_field():
    return False


class Nf(Field):
  """
  represent the nf field
  """

  pattern = re.compile("^nf$")
  memonics = ["", "seg2", "seg3", "seg4", "seg5", "seg6", "seg7", "seg8"]
  encoding = ["000", "001", "010", "011", "100", "101", "110", "111"]

  def __init__(self, index):
    self.index = index

  @staticmethod
  def make(index):
    return Nf(index)

  @staticmethod
  def get_indices():
    return [i for i in range(len(Nf.encoding))]

  def get_memonic(self):
    return Nf.memonics[self.index]

  def get_encoding(self):
    return Nf.encoding[self.index]
  
  @staticmethod
  def is_fixed():
    return False

  @staticmethod
  def depend_on_other_field():
    return False



class Mop(Field):
  """
  represent the mop field
  """

  pattern = re.compile("^mop$")
  encode = ["00", "01", "01"]
  memonics = ["e", "se", "xei"]

  def __init__(self, index):
    self.index = index

  @staticmethod
  def make(index):
    return Mop(index)

  @staticmethod
  def get_indices():
    return [i for i in range(len(Mop.memonics))]

  def get_encoding(self):
    return Mop.encode[self.index]

  def get_memonic(self):
    return Mop.memonics[self.index]

  @staticmethod
  def is_fixed():
    return False
  
  @staticmethod
  def depend_on_other_field():
    return False
  
class Reg(Field):
  """
  represent the register field, and for 
  convenice, I fixed this field to represent 
  only some of the register
  """

  pattern = re.compile("^(vs1)|(vd)|(vs2)|(rs1)|(rs2)")
  regs = {"rs1":"a1", "vs1":"v1", "vd":"v0", "vs2":"v2", "rs2":"a2"}
  regs_encoding = {"vd":"00000", "vs1":"00011", "vs2":"00010", "rs1":"01011", "rs2":"01100"}

  @staticmethod
  def make(text):
    return Reg(text)

  def __init__(self, text):
    self.text = text

  def get_memonic(self):
    return self.regs[self.text]

  def get_encoding(self):
    return self.regs_encoding[self.text]

  @staticmethod
  def depend_on_other_field():
    return False

  @staticmethod
  def is_fixed():
    return True

class FixedBit(Field):
  """
  represent the fixedbit in the instruction pattern
  """

  pattern = re.compile("^[0|1]+$")

  def __init__(self, text):
    self.text = text

  @staticmethod
  def make(text):
    return FixedBit(text)

  def get_memonic(self):
    return ""

  def get_encoding(self):
    return self.text
    
  @staticmethod
  def is_fixed():
    return True

  @staticmethod
  def depend_on_other_field():
    return False


class Format:
  """
  the instruction format, each instance is the set of all the fields
  of the instruction
  """

  def __init__(self, fields, pattern):
    for f in fields:
      assert(not isinstance(f, list))
    self.fields = fields
    self.instruction_pattern = pattern
  
  @staticmethod
  def generate_prologue():
    """
    generate the test file prologue
    """

    print("# RUN: llvm-mc %s -triple=riscv32 -mattr=+v -riscv-no-aliases -show-encoding \\")
    print("# RUN:     | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s")
    print("# RUN: llvm-mc %s -triple=riscv64 -mattr=+v -riscv-no-aliases -show-encoding \\")
    print("# RUN:     | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s")
    print("# RUN: llvm-mc -filetype=obj -triple=riscv32 -mattr=+v < %s \\")
    print("# RUN:     | llvm-objdump --mattr=+v -M no-aliases -d -r - \\")
    print("# RUN:     | FileCheck -check-prefixes=CHECK-OBJ,CHECK-ASM-AND-OBJ %s")
    print("# RUN: llvm-mc -filetype=obj -triple=riscv64 -mattr=+v < %s \\")
    print("# RUN:     | llvm-objdump --mattr=+v -M no-aliases -d -r - \\")
    print("# RUN:     | FileCheck -check-prefixes=CHECK-OBJ,CHECK-ASM-AND-OBJ %s")
    print()
    print()

  def generate_instructions_test(self):
    """
    generate all of the instructions test
    """
    all_posibility = Format.generate_instructions(self.fields)
    for instruction in all_posibility:
      assembly = self.generate_instruction_assembly(instruction)
      encoding = self.generate_instruction_encoding(instruction)
      print("  " + assembly)
      print("# CHECK-ASM-AND-OBJ: 	" + assembly)
      print("# CHECK-ASM: encoding:  [" + encoding + "]")
      print()


  def generate_instruction_assembly(self, instruction):
    """
    generate the instruction assembly string
    """

    current_insns_pattern = self.instruction_pattern[:]
    for i in range(len(current_insns_pattern)):
      if not isinstance(current_insns_pattern[i], str):
        current_insns_pattern[i] = instruction[current_insns_pattern[i]].get_memonic()
    return "".join(current_insns_pattern)

  def generate_instruction_encoding(self, instruction):
    """
    generate the instructino encoding string
    """
    encoding = ""
    for field in instruction:
      if field.depend_on_other_field():
        encoding += field.get_encoding(instruction)
      else:
        encoding += field.get_encoding()
    return Format.convert_binary_to_hex(encoding)

  @staticmethod
  def convert_binary_to_hex(binary):
    """
    convert the binary digit to hex digit form:
    [0x.., 0x.., 0x.., 0x..]
    """
    assert(len(binary) == 32)

    hexdecimal = ""
    while len(binary) > 0:
      part_hexdecimal = hex(int(binary[-8:], 2))
      if len(part_hexdecimal) < 4:
        part_hexdecimal = part_hexdecimal[:2] + "0" + part_hexdecimal[-1]
      hexdecimal += part_hexdecimal
      hexdecimal += ","
      binary = binary[:-8]
    return hexdecimal[:-1]

  @staticmethod
  def generate_instructions(fields):
    for f in fields:
      assert(not isinstance(f, list))
    assert(len(fields) > 0)

    current_field = fields[0]
    if len(fields) == 1:
      if current_field.is_fixed():
        return [[current_field]]
      else:
        return [[current_field.make(i)] for i in current_field.get_indices()]
    
    results = Format.generate_instructions(fields[1:])

    if current_field.is_fixed():
      return [[current_field] + r for r in results]
    else:
      all_posibility = []
      for index in current_field.get_indices():
        all_posibility.extend([[current_field.make(index)] + r
            for r in results])
      return all_posibility

all_fileds = [Width, Mop, Reg, FixedBit, Vm, Mew, Nf]

def process_file(path):
  file = open(path, "r")
  formats = []
  for line in file:
    infos = line.split("---")
    assert(len(infos) == 2)
    format, pattern = tuple(infos)
    matched_fields = process_format(format)
    insns_pattern = process_insns_pattern(pattern)
    formats.append(Format(matched_fields, insns_pattern))
  Format.generate_prologue()
  for format in formats:
    format.generate_instructions_test()

def process_format(format):
  fields = format.split("|")
  matched_fields = []
  for unmatched_field in fields:
    for field in all_fileds:
      if field.pattern.match(unmatched_field):
        if field.is_fixed():
          matched_fields.append(field.make(unmatched_field))
        else:
          matched_fields.append(field)
        break
  return matched_fields

def process_insns_pattern(pattern):
  raw_pattern = pattern.split("|")
  
  # delete the "\n" character in the string
  if raw_pattern[-1][-1] is "\n":
    raw_pattern[-1] = raw_pattern[-1][:-1]
  
  for index in range(len(raw_pattern)):
    if ":" in raw_pattern[index]:
      raw_pattern[index] = int(raw_pattern[index].split(":")[1])
  return raw_pattern
      

process_file("file.txt")