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
        # Input weight 0
        {'description': 'PIND: 0x00 PINB = 0x00 => PORTB = 0x00 ',
        'steps': [ {'inputs': [('PIND',0x00),('PINB',0x00)], 'iterations': 5 } ],
        'expected': [('PORTB',0x00)],
        },
        # Input weight 5
        {'description': 'PIND: 0x02 PINB = 0x01 => PORTB = 0x00 ',
        'steps': [ {'inputs': [('PIND',0x02),('PINB',0x01)], 'iterations': 5 } ],
        'expected': [('PORTB',0x00)],
        },
        # Input weight 6
        {'description': 'PIND: 0x03 PINB = 0x00 => PORTB = 0x04 ',
        'steps': [ {'inputs': [('PIND',0x03),('PINB',0x00)], 'iterations': 5 } ],
        'expected': [('PORTB',0x04)],
        },
        # Input weight 33
        {'description': 'PIND: 0x10 PINB = 0x01 => PORTB = 0x04 ',
        'steps': [ {'inputs': [('PIND',0x10),('PINB',0x01)], 'iterations': 5 } ],
        'expected': [('PORTB',0x04)],
        },
        # Input weight 70
        {'description': 'PIND: 0x23 PINB = 0x00 => PORTB = 0x02 ',
        'steps': [ {'inputs': [('PIND',0x23),('PINB',0x00)], 'iterations': 5 } ],
        'expected': [('PORTB',0x02)],
        },
        # Input weight 150
        {'description': 'PIND: 0x4B PINB = 0x00 => PORTB = 0x02 ',
        'steps': [ {'inputs': [('PIND',0x4B),('PINB',0x00)], 'iterations': 5 } ],
        'expected': [('PORTB',0x02)],
        },
        ]


# Optionally you can add a set of "watch" variables these need to be global or static and may need
# to be scoped at the function level (for static variables) if there are naming conflicts. The 
# variables listed here will display everytime you hit (and stop at) a breakpoint
watch = ['main::weight','PORTB']

