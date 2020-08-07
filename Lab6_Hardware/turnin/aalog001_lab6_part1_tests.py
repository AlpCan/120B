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
        {'description': 'PINA: 0xFF => PORTC: 0x40',
        'steps': [ {'inputs': [('PINA',0xFF)], 'iterations': 5 } ],
        'expected': [('PORTC',0x40)],
        },
        # Input visual 00000001
        {'description': 'PINA: 0xFE => PORTC: 0x60',
        'steps': [ {'inputs': [('PINA',0xFE)], 'iterations': 5 } ],
        'expected': [('PORTC',0x60)],
        },
        # Input visual 00000010
        {'description': 'PINA: 0xFD => PORTC: 0x60',
        'steps': [ {'inputs': [('PINA',0xFD)], 'iterations': 5 } ],
        'expected': [('PORTC',0x60)],
        },
        # Input visual 00000011
        {'description': 'PINA: 0xFC => PORTC: 0x70',
        'steps': [ {'inputs': [('PINA',0xFC)], 'iterations': 5 } ],
        'expected': [('PORTC',0x70)],
        },
        # Input visual 00000100
        {'description': 'PINA: 0xFB => PORTC: 0x70',
        'steps': [ {'inputs': [('PINA',0xFB)], 'iterations': 5 } ],
        'expected': [('PORTC',0x70)],
        },
        # Input visual 00000101
        {'description': 'PINA: 0xFA => PORTC: 0x38',
        'steps': [ {'inputs': [('PINA',0xFA)], 'iterations': 5 } ],
        'expected': [('PORTC',0x38)],
        },
        # Input visual 00000110
        {'description': 'PINA: 0xF9 => PORTC: 0x38',
        'steps': [ {'inputs': [('PINA',0xF9)], 'iterations': 5 } ],
        'expected': [('PORTC',0x38)],
        },
        # Input visual 00000111
        {'description': 'PINA: 0xF8 => PORTC: 0x3C',
        'steps': [ {'inputs': [('PINA',0xF8)], 'iterations': 5 } ],
        'expected': [('PORTC',0x3C)],
        },
        # Input visual 00001000
        {'description': 'PINA: 0xF7 => PORTC: 0x3C',
        'steps': [ {'inputs': [('PINA',0xF7)], 'iterations': 5 } ],
        'expected': [('PORTC',0x3C)],
        },
        # Input visual 00001001
        {'description': 'PINA: 0xF6 => PORTC: 0x3C',
        'steps': [ {'inputs': [('PINA',0xF6)], 'iterations': 5 } ],
        'expected': [('PORTC',0x3C)],
        },
        # Input visual 00001010
        {'description': 'PINA: 0xF5 => PORTC: 0x3E',
        'steps': [ {'inputs': [('PINA',0xF5)], 'iterations': 5 } ],
        'expected': [('PORTC',0x3E)],
        },
        # Input visual 00001011
        {'description': 'PINA: 0xF4 => PORTC: 0x3E',
        'steps': [ {'inputs': [('PINA',0xF4)], 'iterations': 5 } ],
        'expected': [('PORTC',0x3E)],
        },
        # Input visual 00001100
        {'description': 'PINA: 0xF3 => PORTC: 0x3E',
        'steps': [ {'inputs': [('PINA',0xF3)], 'iterations': 5 } ],
        'expected': [('PORTC',0x3E)],
        },
        # Input visual 00001101
        {'description': 'PINA: 0xF2 => PORTC: 0x3F',
        'steps': [ {'inputs': [('PINA',0xF2)], 'iterations': 5 } ],
        'expected': [('PORTC',0x3F)],
        },
        # Input visual 00001110
        {'description': 'PINA: 0xF1 => PORTC: 0x3F',
        'steps': [ {'inputs': [('PINA',0xF1)], 'iterations': 5 } ],
        'expected': [('PORTC',0x3F)],
        },
        # Input visual 00001111
        {'description': 'PINA: 0xF0 => PORTC: 0x3F',
        'steps': [ {'inputs': [('PINA',0xF0)], 'iterations': 5 } ],
        'expected': [('PORTC',0x3F)],
        },
        # Input visual 11111111
        {'description': 'PINA: 0x00 => PORTC: 0x3F',
        'steps': [ {'inputs': [('PINA',0x00)], 'iterations': 5 } ],
        'expected': [('PORTC',0x3F)],
        },
        
        ]

# Optionally you can add a set of "watch" variables these need to be global or static and may need
# to be scoped at the function level (for static variables) if there are naming conflicts. The 
# variables listed here will display everytime you hit (and stop at) a breakpoint
#watch = ['<function>::<static-var>','PORTB']

