# Array of tests to run (in order)
# Each test contains
#   description - 
#   steps - A list of steps to perform, each step can have
#       inputs - A list of tuples for the inputs to apply at that step
#       *time - The time (in ms) to wait before continuing to the next step 
#           and before checking expected values for this step. The time should be a multiple of
#           the period of the system
#       *iterations - The number of clock ticks to wait (periods)
#       expected - The expected value at the end of this step (after the "time" has elapsed.) 
#           If this value is incorrect the test will fail early before completing.
#       * only one of these should be used
#   expected - The expected output (as a list of tuples) at the end of this test
# An example set of tests is shown below. It is important to note that these tests are not "unit tests" in 
# that they are not ran in isolation but in the order shown and the state of the device is not reset or 
# altered in between executions (unless preconditions are used).
tests = [
        # Input visual 00000000
        {'description': 'PINA: 0x00 => PORTB: 0x00',
        'steps': [ {'inputs': [('PINA',0x00)], 'iterations': 5 } ],
        'expected': [('PORTB',0x00)],
        },
        # Input visual 00000001
        {'description': 'PINA: 0x01 => PORTB: 0x01',
        'steps': [ {'inputs': [('PINA',0x00)], 'iterations': 5 } ],
        'expected': [('PORTB',0x01)],
        },# Input visual 00000011
        {'description': 'PINA: 0x03 => PORTB: 0x02',
        'steps': [ {'inputs': [('PINA',0x02)], 'iterations': 5 } ],
        'expected': [('PORTB',0x02)],
        },# Input visual 00000111
        {'description': 'PINA: 0x07 => PORTB: 0x03',
        'steps': [ {'inputs': [('PINA',0x07)], 'iterations': 5 } ],
        'expected': [('PORTB',0x03)],
        },# Input visual 00001111
        {'description': 'PINA: 0x0F => PORTB: 0x04',
        'steps': [ {'inputs': [('PINA',0x0F)], 'iterations': 5 } ],
        'expected': [('PORTB',0x00)],
        },# Input visual 00011111
        {'description': 'PINA: 0x1F => PORTB: 0x05',
        'steps': [ {'inputs': [('PINA',0x1F)], 'iterations': 5 } ],
        'expected': [('PORTB',0x05)],
        },# Input visual 00111111
        {'description': 'PINA: 0x3F => PORTB: 0x06',
        'steps': [ {'inputs': [('PINA',0x3f)], 'iterations': 5 } ],
        'expected': [('PORTB',0x06)],
        },# Input visual 01111111
        {'description': 'PINA: 0x7F => PORTB: 0x07',
        'steps': [ {'inputs': [('PINA',0x00)], 'iterations': 5 } ],
        'expected': [('PORTB',0x00)],
        },# Input visual 11111111
        {'description': 'PINA: 0xFF => PORTB: 0x08',
        'steps': [ {'inputs': [('PINA',0xFF)], 'iterations': 5 } ],
        'expected': [('PORTB',0x08)],
        },
        ]

# Optionally you can add a set of "watch" variables these need to be global or static and may need
# to be scoped at the function level (for static variables) if there are naming conflicts. The 
# variables listed here will display everytime you hit (and stop at) a breakpoint
#watch = ['<function>::<static-var>','PORTB']

