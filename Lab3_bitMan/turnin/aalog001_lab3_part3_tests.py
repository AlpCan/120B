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
        {'description': 'PINA: 0 => PORTC: 0x40',
        'steps': [ {'inputs': [('PINA',0)], 'iterations': 5 } ],
        'expected': [('PORTC',0x00)],
        },
        # Input visual 00000001
        {'description': 'PINA: 0x01 => PORTC: 0x60',
        'steps': [ {'inputs': [('PINA',0x01)], 'iterations': 5 } ],
        'expected': [('PORTC',0x60)],
        },
        # Input visual 00000010
        {'description': 'PINA: 0x02 => PORTC: 0x60',
        'steps': [ {'inputs': [('PINA',0x02)], 'iterations': 5 } ],
        'expected': [('PORTC',0x60)],
        },
        # Input visual 00000011
        {'description': 'PINA: 0x03 => PORTC: 0x70',
        'steps': [ {'inputs': [('PINA',0x03)], 'iterations': 5 } ],
        'expected': [('PORTC',0x70)],
        },
        # Input visual 00000100
        {'description': 'PINA: 0x04 => PORTC: 0x70',
        'steps': [ {'inputs': [('PINA',0x04)], 'iterations': 5 } ],
        'expected': [('PORTC',0x70)],
        },
        # Input visual 00000101
        {'description': 'PINA: 0x05 => PORTC: 0x38',
        'steps': [ {'inputs': [('PINA',0x05)], 'iterations': 5 } ],
        'expected': [('PORTC',0x38)],
        },
        # Input visual 00000110
        {'description': 'PINA: 0x06 => PORTC: 0x38',
        'steps': [ {'inputs': [('PINA',0x06)], 'iterations': 5 } ],
        'expected': [('PORTC',0x38)],
        },
        # Input visual 00000111
        {'description': 'PINA: 0x07 => PORTC: 0x3C',
        'steps': [ {'inputs': [('PINA',0x07)], 'iterations': 5 } ],
        'expected': [('PORTC',0x3C)],
        },
        # Input visual 00001000
        {'description': 'PINA: 0x08 => PORTC: 0x3C',
        'steps': [ {'inputs': [('PINA',0x08)], 'iterations': 5 } ],
        'expected': [('PORTC',0x3C)],
        },
        # Input visual 00001001
        {'description': 'PINA: 0x09 => PORTC: 0x3C',
        'steps': [ {'inputs': [('PINA',0x09)], 'iterations': 5 } ],
        'expected': [('PORTC',0x3C)],
        },
        # Input visual 00001010
        {'description': 'PINA: 0x0A => PORTC: 0x3E',
        'steps': [ {'inputs': [('PINA',0x0A)], 'iterations': 5 } ],
        'expected': [('PORTC',0x3E)],
        },
        # Input visual 00001011
        {'description': 'PINA: 0x0B => PORTC: 0x3E',
        'steps': [ {'inputs': [('PINA',0x0B)], 'iterations': 5 } ],
        'expected': [('PORTC',0x3E)],
        },
        # Input visual 00001100
        {'description': 'PINA: 0x0C => PORTC: 0x3E',
        'steps': [ {'inputs': [('PINA',0x0C)], 'iterations': 5 } ],
        'expected': [('PORTC',0x3E)],
        },
        # Input visual 00001101
        {'description': 'PINA: 0x0D => PORTC: 0x3F',
        'steps': [ {'inputs': [('PINA',0x0D)], 'iterations': 5 } ],
        'expected': [('PORTC',0x3F)],
        },
        # Input visual 00001110
        {'description': 'PINA: 0x0E => PORTC: 0x3F',
        'steps': [ {'inputs': [('PINA',0x0E)], 'iterations': 5 } ],
        'expected': [('PORTC',0x3F)],
        },
        # Input visual 00001111
        {'description': 'PINA: 0x0F => PORTC: 0x3F',
        'steps': [ {'inputs': [('PINA',0x0F)], 'iterations': 5 } ],
        'expected': [('PORTC',0x3F)],
        },
        # Input visual 11111111
        {'description': 'PINA: 0xFF => PORTC: 0x3F',
        'steps': [ {'inputs': [('PINA',0xFF)], 'iterations': 5 } ],
        'expected': [('PORTC',0x3F)],
        },
        # Input visual 00111111
        {'description': 'PINA: 0x6F => PORTC: 0x3F',
        'steps': [ {'inputs': [('PINA',0x6F)], 'iterations': 5 } ],
        'expected': [('PORTC',0x3F)],
        },# Input visual 01001111
        {'description': 'PINA: 0x4F => PORTC: 0x3F',
        'steps': [ {'inputs': [('PINA',0x4F)], 'iterations': 5 } ],
        'expected': [('PORTC',0x3F)],
        },# Input visual 00111111
        {'description': 'PINA: 0x3F => PORTC: 0xBF',
        'steps': [ {'inputs': [('PINA',0x3F)], 'iterations': 5 } ],
        'expected': [('PORTC',0xBF)],
        },

        
        ]

# Optionally you can add a set of "watch" variables these need to be global or static and may need
# to be scoped at the function level (for static variables) if there are naming conflicts. The 
# variables listed here will display everytime you hit (and stop at) a breakpoint
watch = ['main::keyIgn','main::seated','main::seatBelt','PORTC']

