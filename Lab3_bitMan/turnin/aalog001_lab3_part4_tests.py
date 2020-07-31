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
        {'description': 'PINA: 0x00 => PORTB = 0x00 PORTC: 0x00',
        'steps': [ {'inputs': [('PINA',0x00)], 'iterations': 5 } ],
        'expected': [('PORTC',0x00),('PORTB',0x00)],
        },
        # Input visual 00000001
        {'description': 'PINA: 0x01 => PORTB = 0x00 PORTC: 0x10',
        'steps': [ {'inputs': [('PINA',0x01)], 'iterations': 5 } ],
        'expected': [('PORTC',0x10),('PORTB',0x00)],
        },
        # Input visual 00000010
        {'description': 'PINA: 0x02 =>  PORTB = 0x00 PORTC: 0x20',
        'steps': [ {'inputs': [('PINA',0x02)], 'iterations': 5 } ],
        'expected': [('PORTC',0x20),('PORTB',0x00)],
        },
        # Input visual 00000011
        {'description': 'PINA: 0x03 =>  PORTB = 0x00 PORTC: 0x30',
        'steps': [ {'inputs': [('PINA',0x03)], 'iterations': 5 } ],
        'expected': [('PORTC',0x30)],
        },
        # Input visual 00000100
        {'description': 'PINA: 0x04 =>  PORTB = 0x00 PORTC: 0x40',
        'steps': [ {'inputs': [('PINA',0x04)], 'iterations': 5 } ],
        'expected': [('PORTB',0x00),('PORTC',0x40)],
        },
        # Input visual 00000101
        {'description': 'PINA: 0x05 =>  PORTB = 0x00 PORTC: 0x50',
        'steps': [ {'inputs': [('PINA',0x05)], 'iterations': 5 } ],
        'expected': [('PORTB',0x00),('PORTC',0x50)],
        },
        # Input visual 00000110
        {'description': 'PINA: 0x06 =>  PORTB = 0x00 PORTC: 0x60',
        'steps': [ {'inputs': [('PINA',0x06)], 'iterations': 5 } ],
        'expected': [('PORTB',0x00),('PORTC',0x60)],
        },
        # Input visual 00000111
        {'description': 'PINA: 0x07 =>  PORTB = 0x00 PORTC: 0x70',
        'steps': [ {'inputs': [('PINA',0x07)], 'iterations': 5 } ],
        'expected': [('PORTB',0x00),('PORTC',0x70)],
        },
        # Input visual 00001000
        {'description': 'PINA: 0x08 => PORTB = 0x00  PORTC: 0x80',
        'steps': [ {'inputs': [('PINA',0x08)], 'iterations': 5 } ],
        'expected': [('PORTB',0x00),('PORTC',0x80)],
        },
        # Input visual 00011111
        {'description': 'PINA: 0x1F =>  PORTB = 0x01 PORTC: 0xF0',
        'steps': [ {'inputs': [('PINA',0x1F)], 'iterations': 5 } ],
        'expected': [('PORTB',0x01),('PORTC',0xF0)],
        },
        # Input visual 00101111
        {'description': 'PINA: 0x2F => PORTB = 0x02  PORTC: 0xF0',
        'steps': [ {'inputs': [('PINA',0x2F)], 'iterations': 5 } ],
        'expected': [('PORTB',0x02),('PORTC',0xF0)],
        },
        # Input visual 00110000
        {'description': 'PINA: 0x30 => PORTB = 0x30  PORTC: 0x00',
        'steps': [ {'inputs': [('PINA',0x30)], 'iterations': 5 } ],
        'expected': [('PORTB',0x03),('PORTC',0x00)],
        },
        # Input visual 01001111
        {'description': 'PINA: 0x4F => PORTB = 0x40  PORTC: 0xF0',
        'steps': [ {'inputs': [('PINA',0x4F)], 'iterations': 5 } ],
        'expected': [('PORTB',0x04),('PORTC',0xF0)],
        },
        ]


# Optionally you can add a set of "watch" variables these need to be global or static and may need
# to be scoped at the function level (for static variables) if there are naming conflicts. The 
# variables listed here will display everytime you hit (and stop at) a breakpoint
#watch = ['main::keyIgn','main::seated','main::seatBelt','PORTC']

