#pragma once

extern const uint8_t font8[96][6] = {
    {4, 0b00000000, 0b00000000, 0b00000000, 0b00000000},             // 32              = Space
    {1, 0b11111011},                                                 // 33                                                  = !
    {3, 0b11100000, 0b00000000, 0b11100000},                         // 34                          = "
    {5, 0b00101000, 0b11111110, 0b00101000, 0b11111110, 0b00101000}, // 35  = #
    {5, 0b00100100, 0b01010100, 0b11111110, 0b01010100, 0b01001000}, // 36  = $
    {5, 0b11000100, 0b11001000, 0b00010000, 0b00100110, 0b01000110}, // 37  = %
    {5, 0b01101100, 0b10010010, 0b10010010, 0b01101100, 0b00001010}, // 38  = &
    {2, 0b00100000, 0b11000000},                                     // 39                                      = '
    {2, 0b01111100, 0b10000010},                                     // 40                                      = (
    {2, 0b10000010, 0b01111100},                                     // 41                                      = )
    {5, 0b00101000, 0b00111000, 0b01111100, 0b00111000, 0b00101000}, // 42  = *
    {5, 0b00010000, 0b00010000, 0b01111100, 0b00010000, 0b00010000}, // 43  = +
    {4, 0b00000000, 0b00000101, 0b00000110, 0b00000000},             // 44              = ,
    {4, 0b00010000, 0b00010000, 0b00010000, 0b00010000},             // 45              = -
    {4, 0b00000000, 0b00000110, 0b00000110, 0b00000000},             // 46              = .
    {5, 0b00000100, 0b00001000, 0b00010000, 0b00100000, 0b01000000}, // 47  = /
    {5, 0b01111100, 0b10000010, 0b10000010, 0b10000010, 0b01111100}, // 48  = 0
    {3, 0b01000010, 0b11111110, 0b00000010},                         // 49                          = 1
    {5, 0b01001110, 0b10010010, 0b10010010, 0b10010010, 0b01100010}, // 50  = 2
    {5, 0b01000100, 0b10000010, 0b10010010, 0b10010010, 0b01101100}, // 51  = 3
    {5, 0b00011000, 0b00101000, 0b01001000, 0b11111110, 0b00001000}, // 52  = 4
    {5, 0b11100100, 0b10100010, 0b10100010, 0b10100010, 0b10011100}, // 53  = 5
    {5, 0b01111100, 0b10010010, 0b10010010, 0b10010010, 0b01001100}, // 54  = 6
    {5, 0b10000000, 0b10000110, 0b10011000, 0b10100000, 0b11000000}, // 55  = 7
    {5, 0b01101100, 0b10010010, 0b10010010, 0b10010010, 0b01101100}, // 56  = 8
    {5, 0b01100100, 0b10010010, 0b10010010, 0b10010010, 0b01111100}, // 57  = 9
    {4, 0b00000000, 0b00110110, 0b00110110, 0b00000000},             // 58              = :
    {4, 0b00000000, 0b00110101, 0b00110110, 0b00000000},             // 59              = ;
    {4, 0b00010000, 0b00101000, 0b01000100, 0b10000010},             // 60              = <
    {4, 0b00101000, 0b00101000, 0b00101000, 0b00101000},             // 61              = =
    {4, 0b10000010, 0b01000100, 0b00101000, 0b00010000},             // 62              = >
    {5, 0b01000000, 0b10000000, 0b10001010, 0b10010000, 0b01100000}, // 63  = ?
    {5, 0b01111100, 0b10000010, 0b10010010, 0b10101010, 0b01111000}, // 64  = @
    {5, 0b00000110, 0b00111000, 0b11001000, 0b00111000, 0b00000110}, // 65  = A
    {5, 0b11111110, 0b10010010, 0b10010010, 0b10010010, 0b01101100}, // 66  = B
    {5, 0b01111100, 0b10000010, 0b10000010, 0b10000010, 0b01000100}, // 67  = C
    {5, 0b11111110, 0b10000010, 0b10000010, 0b01000100, 0b00111000}, // 68  = D
    {5, 0b11111110, 0b10010010, 0b10010010, 0b10010010, 0b10000010}, // 69  = E
    {5, 0b11111110, 0b10010000, 0b10010000, 0b10010000, 0b10000000}, // 70  = F
    {5, 0b01111100, 0b10000010, 0b10000010, 0b10010010, 0b10011110}, // 71  = G
    {5, 0b11111110, 0b00010000, 0b00010000, 0b00010000, 0b11111110}, // 72  = H
    {3, 0b10000010, 0b11111110, 0b10000010},                         // 73                          = I
    {4, 0b00000100, 0b00000010, 0b10000010, 0b11111100},             // 74              = J
    {5, 0b11111110, 0b00010000, 0b00101000, 0b01000100, 0b10000010}, // 75  = K
    {5, 0b11111110, 0b00000010, 0b00000010, 0b00000010, 0b00000010}, // 76  = L
    {5, 0b11111110, 0b01000000, 0b00110000, 0b01000000, 0b11111110}, // 77  = M
    {5, 0b11111110, 0b01100000, 0b00010000, 0b00001100, 0b11111110}, // 78  = N
    {5, 0b01111100, 0b10000010, 0b10000010, 0b10000010, 0b01111100}, // 79  = O
    {5, 0b11111110, 0b10010000, 0b10010000, 0b10010000, 0b01100000}, // 80  = P
    {5, 0b01111100, 0b10000010, 0b10001010, 0b10000100, 0b01111010}, // 81  = Q
    {5, 0b11111110, 0b10010000, 0b10011000, 0b10010100, 0b01100010}, // 82  = R
    {5, 0b01100100, 0b10110010, 0b10010010, 0b10010010, 0b01001100}, // 83  = S
    {5, 0b10000000, 0b10000000, 0b11111110, 0b10000000, 0b10000000}, // 84  = T
    {5, 0b11111100, 0b00000010, 0b00000010, 0b00000010, 0b11111100}, // 85  = U
    {5, 0b11100000, 0b00011000, 0b00000110, 0b00011000, 0b11100000}, // 86  = V
    {5, 0b11110000, 0b00001110, 0b00110000, 0b00001110, 0b11110000}, // 87  = W
    {5, 0b11000110, 0b00101000, 0b00010000, 0b00101000, 0b11000110}, // 88  = X
    {5, 0b11000000, 0b00100000, 0b00011110, 0b00100000, 0b11000000}, // 89  = Y
    {5, 0b10000110, 0b10001010, 0b10010010, 0b10100010, 0b11000010}, // 90  = Z
    {3, 0b11111110, 0b10000010, 0b10000010},                         // 91                          = [
    {5, 0b01000000, 0b00100000, 0b00010000, 0b00001000, 0b00000100}, // 92  = Backslash
    {3, 0b10000010, 0b10000010, 0b11111110},                         // 93                          = ]
    {5, 0b00100000, 0b01000000, 0b10000000, 0b01000000, 0b00100000}, // 94  = ^
    {5, 0b00000010, 0b00000010, 0b00000010, 0b00000010, 0b00000010}, // 95  = _
    {2, 0b11000000, 0b00100000},                                     // 96                                      = `
    {5, 0b00000100, 0b00101010, 0b00101010, 0b00101010, 0b00011110}, // 97  = a
    {5, 0b11111110, 0b00100010, 0b00100010, 0b00100010, 0b00011100}, // 98  = b
    {5, 0b00011100, 0b00100010, 0b00100010, 0b00100010, 0b00100010}, // 99  = c
    {5, 0b00011100, 0b00100010, 0b00100010, 0b00100010, 0b11111110}, // 100 = d
    {5, 0b00011100, 0b00101010, 0b00101010, 0b00101010, 0b00011010}, // 101 = e
    {4, 0b00010000, 0b01111110, 0b10010000, 0b10010000},             // 102             = f
    {5, 0b00011000, 0b00100101, 0b00100101, 0b00100101, 0b00111110}, // 103 = g
    {5, 0b11111110, 0b00100000, 0b00100000, 0b00100000, 0b00011110}, // 104 = h
    {2, 0b10111100, 0b00000010},                                     // 105                                     = i
    {3, 0b00000010, 0b00000001, 0b10111110},                         // 106                         = j
    {4, 0b11111110, 0b00001000, 0b00010100, 0b00100010},             // 107             = k
    {2, 0b11111100, 0b00000010},                                     // 108                                     = l
    {5, 0b00111110, 0b00100000, 0b00011110, 0b00100000, 0b00011110}, // 109 = m
    {5, 0b00111110, 0b00100000, 0b00100000, 0b00100000, 0b00011110}, // 110 = n
    {5, 0b00011100, 0b00100010, 0b00100010, 0b00100010, 0b00011100}, // 111 = o
    {5, 0b00111111, 0b00100100, 0b00100100, 0b00100100, 0b00011000}, // 112 = p
    {5, 0b00011100, 0b00100010, 0b00100010, 0b00100100, 0b00111111}, // 113 = q
    {4, 0b00111110, 0b00010000, 0b00100000, 0b00100000},             // 114             = r
    {5, 0b00010010, 0b00101010, 0b00101010, 0b00101010, 0b00100100}, // 115 = s
    {3, 0b00100000, 0b01111100, 0b00100010},                         // 116                         = t
    {5, 0b00111100, 0b00000010, 0b00000010, 0b00000100, 0b00111110}, // 117 = u
    {5, 0b00110000, 0b00001100, 0b00000010, 0b00001100, 0b00110000}, // 118 = v
    {5, 0b00111000, 0b00000110, 0b00111000, 0b00000110, 0b00111000}, // 119 = w
    {5, 0b00100010, 0b00010100, 0b00001000, 0b00010100, 0b00100010}, // 120 = x
    {5, 0b00111000, 0b00000101, 0b00000101, 0b00000101, 0b00111110}, // 121 = y
    {5, 0b00100010, 0b00100110, 0b00101010, 0b00110010, 0b00100010}, // 122 = z
    {3, 0b00010000, 0b01101100, 0b10000010},                         // 123                         = {
    {1, 0b11111111},                                                 // 124                                                 = |
    {3, 0b10000010, 0b01101100, 0b00010000},                         // 125                         = }
    {
        4,
        0b01000000,
        0b10000000,
        0b01000000,
        0b10000000,
    },                                                              // 126           = ~
    {5, 0b00111000, 0b00101000, 0b01101100, 0b00101000, 0b00010000} // 127  = DEL
};
