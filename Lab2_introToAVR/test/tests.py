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
    # Empty ride
    {'description': 'PINA: 0x00, PINB: 0x00, PINC: 0x00  => PORTD: 0x00',
    'steps': [ {'inputs': [('PINA',0x00),('PINB',0x00),('PINC',0x00)], 'iterations': 5 } ],
    'expected': [('PORTD',0x00)],
    },
    #Unbalanced ride test, w/ under 140kg, seatA is bigger than seat C
    {'description': 'PINA: 0x80, PINB: 0x00, PINC: 0x00  => PORTD: 0x22',
    'steps': [ {'inputs': [('PINA',0x80),('PINB',0x00),('PINC',0x00)], 'iterations': 5 } ],
    'expected': [('PORTD',0x22)],
    },
    #Unbalanced ride test, w/ under 140kg, seatA is smaller than seat C
    {'description': 'PINA: 0x00, PINB: 0x00, PINC: 0x80  => PORTD: 0x22',
    'steps': [ {'inputs': [('PINA',0x00),('PINB',0x00),('PINC',0x80)], 'iterations': 5 } ],
    'expected': [('PORTD',0x22)],
    },
    #Unbalanced ride test, w/ over 140kg, seatA is smaller than seat C
    {'description': 'PINA: 0x00, PINB: 65, PINC: 80  => PORTD: 0x25',
    'steps': [ {'inputs': [('PINA',0x00),('PINB',65),('PINC',80)], 'iterations': 5 } ],
    'expected': [('PORTD',0x25)],
    },
    #Unbalanced ride test, w/ over 140kg, seatA is bigger than seat C
    {'description': 'PINA: 80, PINB: 65, PINC: 0  => PORTD: 0x25',
    'steps': [ {'inputs': [('PINA',80),('PINB',65),('PINC',0)], 'iterations': 5 } ],
    'expected': [('PORTD',0x25)],
    },
    #Unbalanced ride test, w/ over 140kg, seatA over 140
    {'description': 'PINA: 0xC0, PINB: 0x00, PINC: 0x00  => PORTD: 0x33',
    'steps': [ {'inputs': [('PINA',0xC0),('PINB',0x00),('PINC',0x00)], 'iterations': 5 } ],
    'expected': [('PORTD',0x33)],
    },
    #Unbalanced ride test, w/ over 140kg, seat C over 140
    {'description': 'PINA: 0x00, PINB: 0x00, PINC: 0xC0  => PORTD: 0x33',
    'steps': [ {'inputs': [('PINA',0x00),('PINB',0x00),('PINC',0xC0)], 'iterations': 5 } ],
    'expected': [('PORTD',0x33)],
    },
    #balanced ride test, w/ over 140kg, seat B over 140
    {'description': 'PINA: 0x00, PINB: 0xC0, PINC: 0x00  => PORTD: 0x31',
    'steps': [ {'inputs': [('PINA',0x00),('PINB',0xC0),('PINC',0x00)], 'iterations': 5 } ],
    'expected': [('PORTD',0x31)],
    },
    #balanced ride test, w/ under 140kg
    {'description': 'PINA: 0x20, PINB: 0x20, PINC: 0x20  => PORTD: 0x18',
    'steps': [ {'inputs': [('PINA',0x20),('PINB',0x20),('PINC',0x20)], 'iterations': 5 } ],
    'expected': [('PORTD',0x18)],
    },
    #balanced ride test, w/ over 140kg
    {'description': 'PINA: 40 , PINB: 20, PINC: 40  => PORTD: 0x18',
    'steps': [ {'inputs': [('PINA',40),('PINB',20),('PINC',40)], 'iterations': 5 } ],
    'expected': [('PORTD',0x18)],
    },
    ]

# Optionally you can add a set of "watch" variables these need to be global or static and may need
# to be scoped at the function level (for static variables) if there are naming conflicts. The 
# variables listed here will display everytime you hit (and stop at) a breakpoint
#watch = ['main::result','main::tempT','PORTD']

