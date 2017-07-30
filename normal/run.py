#! /usr/local/python3
import sys
from pprint import pprint
import argparse
import os
import re

compile_template = { # Used to compile (or check) files
  'cpp': 'g++ -o {output_name} -Wall -ggdb {file}',
  'c': 'gcc -o {output_name} -Wall -ggdb {file}',
  'pascal': 'fpc -O{output_name} {file}',
  'py3': 'python3 -m py_compile {file}',
  'py2': 'python2 -m py_compile {file}'
}

run_template = { # Used to run files
  'cpp': '{output}',
  'c': '{output}',
  'pascal': '{output}',
  'py3': 'python3 {file}',
  'py2': 'python2 {file}'
}

delete_template = {
  'posix': 'rm -f {output} {output}.dSYM',
  'nt': 'del {output}'
}

clear_template = {
  'posix': 'clear',
  'nt': 'cls'
}

type_regex = { # Used to detect file type automatically
  'cpp': r'^.*\.cpp$',
  'c': r'^.*\.c$',
  'pascal': r'^.*\.pas$',
  'py3': r'^.*\.py$'
}

default_output_name = {
  'posix': 'a.out',
  'nt': 'a.exe'
}

parser = argparse.ArgumentParser(description='Compile and run any code.',)
parser.add_argument('file', help='the code file you want to run (or check)')
parser.add_argument('-c', '--compile-only', help='only compile the file', action='store_true')
parser.add_argument('--type', type=str, help='specify code type: ' + ', '.join([x for x in compile_template]))
parser.add_argument('-q', '--quiet', help='do not show any message except the stdout', action='store_true')
# parser.add_argument('-I', '--in-file', type=str, help='the input for the code')
# parser.add_argument('-O', '--out-file', type=str, help='the file to save the output of the code')
args = parser.parse_args()

file_info = {
  'file': os.path.abspath(args.file),
  'output_name': default_output_name[os.name],
  'dir': os.getcwd()
}
file_info['output'] = os.path.abspath(file_info['output_name'])

if args.type is None: # then detect file type
  for i in type_regex:
    if re.match(type_regex[i], args.file) is not None:
      file_info['type'] = i
  if not 'type' in file_info:
    exit("Error: unknown file type")
elif args.type in compile_template:
  file_info['type'] = args.type
else:
  exit("Error: unsupported file type")

os.system(clear_template[os.name])
# Compile the file
if not args.quiet:
  print('Compiling {file} as a {type} file'.format(**file_info))
status = os.system(compile_template[file_info['type']].format(**file_info))
if status != 0:
  exit('Failed to compile')
if not args.compile_only: # then run the file
  if not args.quiet:
    print('Start the program\n' + 'START'.center(20, '-'))
  status = os.system(run_template[file_info['type']].format(**file_info))
  if not args.quiet:
    print('END'.center(20, '-') + '\nProgram exited with status {}'.format(status))
# Delete executable file
os.system(delete_template[os.name].format(**file_info))
