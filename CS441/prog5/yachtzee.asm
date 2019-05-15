.constant TERM 0x4000
.constant KEYB 0x4002

.variable dice[5]
.variable count[6]

    MOVI r0 = 0

    # deadbeef initializers
    MOVI r2 = 2
    MOVI r100 = 42            # random number generator seed
    MOVI r101 = 0xdeadbeef    # random number generator intial value
    MOVI r123 = 0

    MOVI r150 = 0             # starting die
    MOVI r151 = 6             # num of all dice

    MOVI r160 = 0             # die "1"
    MOVI r161 = 1             # die "2"
    MOVI r162 = 2             # die "3"
    MOVI r163 = 3             # die "4"
    MOVI r164 = 4             # die "5"
    MOVI r165 = 5             # die "6"

    MOVI r166 = 0             # 0 for straight
    MOVI r167 = 2             # 2 for full house
    MOVI r168 = 3             # 3 of a kind
    MOVI r169 = 4             # 4 of a kind
    MOVI r170 = 5             # yachtzee!

    MOVI r222 = 3             # num of rows
    MOVI r223 = 0             # row
    MOVI r224 = 5             # num of dice

    MOVI r240 = 0x7c          # pipe
    MOVI r241 = 0x20          # space
    MOVI r242 = 0x2f          # slash
    MOVI r243 = 0x5f          # underscore
    MOVI r244 = 0xa           # line feed
    MOVI r245 = 0x2b          # plus
    MOVI r246 = 0x2d          # hypen

    BRA  [!inf]

!roll_dice
!deadbeef
    # r100 = deadbeef_seed
    # r101 = deadbeef_beef
    SHL  r99 = r100 << 7
    SHR  r100 = r100 >> 25
    ADD  r100 = r100 + r101
    EXOR r100 = r99 ^ r100

    SHL  r99 = r101 << 7
    SHR  r101 = r101 >> 25
    EXOR r101 = r99 ^ (r101 + 0xdeadbeef)

    AND  r100 = r100 & 0x7fffffff
    MOD  r100 = r100 % 6
    ADD  r100 = r100 + '1'

    STOR [r150 + dice] = r100
    LOAD r105 = [r150 + dice]
    INC  r150
    BRAL [!roll_dice], r150 < r224
    MOVI r150 = 0
    BRA  [!print_frame]

!print_frame
#######################################
!line_1

    STOR [TERM] = r241
    STOR [TERM] = r241
    STOR [TERM] = r243
    STOR [TERM] = r243
    STOR [TERM] = r243
    STOR [TERM] = r243
    STOR [TERM] = r243
    STOR [TERM] = r243
    STOR [TERM] = r241
    STOR [TERM] = r241

    STOR [TERM] = r241
    STOR [TERM] = r241
    STOR [TERM] = r243
    STOR [TERM] = r243
    STOR [TERM] = r243
    STOR [TERM] = r243
    STOR [TERM] = r243
    STOR [TERM] = r243
    STOR [TERM] = r241
    STOR [TERM] = r241

    STOR [TERM] = r241
    STOR [TERM] = r241
    STOR [TERM] = r243
    STOR [TERM] = r243
    STOR [TERM] = r243
    STOR [TERM] = r243
    STOR [TERM] = r243
    STOR [TERM] = r243
    STOR [TERM] = r241
    STOR [TERM] = r241

    STOR [TERM] = r241
    STOR [TERM] = r241
    STOR [TERM] = r243
    STOR [TERM] = r243
    STOR [TERM] = r243
    STOR [TERM] = r243
    STOR [TERM] = r243
    STOR [TERM] = r243
    STOR [TERM] = r241
    STOR [TERM] = r241

    STOR [TERM] = r241
    STOR [TERM] = r241
    STOR [TERM] = r243
    STOR [TERM] = r243
    STOR [TERM] = r243
    STOR [TERM] = r243
    STOR [TERM] = r243
    STOR [TERM] = r243
    STOR [TERM] = r241
    STOR [TERM] = r241

    STOR [TERM] = r244
    
!line_2
    STOR [TERM] = r241
    STOR [TERM] = r242
    STOR [TERM] = r241
    STOR [TERM] = r241
    STOR [TERM] = r241
    STOR [TERM] = r241
    STOR [TERM] = r241
    STOR [TERM] = r242
    STOR [TERM] = r240 
    STOR [TERM] = r241
    STOR [TERM] = r241
    
    STOR [TERM] = r242
    STOR [TERM] = r241
    STOR [TERM] = r241
    STOR [TERM] = r241
    STOR [TERM] = r241
    STOR [TERM] = r241
    STOR [TERM] = r242
    STOR [TERM] = r240 
    STOR [TERM] = r241
    STOR [TERM] = r241
    
    STOR [TERM] = r242
    STOR [TERM] = r241
    STOR [TERM] = r241
    STOR [TERM] = r241
    STOR [TERM] = r241
    STOR [TERM] = r241
    STOR [TERM] = r242
    STOR [TERM] = r240 
    STOR [TERM] = r241
    STOR [TERM] = r241
    
    STOR [TERM] = r242
    STOR [TERM] = r241
    STOR [TERM] = r241
    STOR [TERM] = r241
    STOR [TERM] = r241
    STOR [TERM] = r241
    STOR [TERM] = r242
    STOR [TERM] = r240 
    STOR [TERM] = r241
    STOR [TERM] = r241
    
    STOR [TERM] = r242
    STOR [TERM] = r241
    STOR [TERM] = r241
    STOR [TERM] = r241
    STOR [TERM] = r241
    STOR [TERM] = r241
    STOR [TERM] = r242
    STOR [TERM] = r240 
    STOR [TERM] = r241
    STOR [TERM] = r241
    STOR [TERM] = r244

!line_3
    STOR [TERM] = r245
    STOR [TERM] = r246
    STOR [TERM] = r246
    STOR [TERM] = r246
    STOR [TERM] = r246
    STOR [TERM] = r246
    STOR [TERM] = r245
    STOR [TERM] = r241
    STOR [TERM] = r240
    STOR [TERM] = r241
    
    STOR [TERM] = r245
    STOR [TERM] = r246
    STOR [TERM] = r246
    STOR [TERM] = r246
    STOR [TERM] = r246
    STOR [TERM] = r246
    STOR [TERM] = r245
    STOR [TERM] = r241
    STOR [TERM] = r240
    STOR [TERM] = r241
    
    STOR [TERM] = r245
    STOR [TERM] = r246
    STOR [TERM] = r246
    STOR [TERM] = r246
    STOR [TERM] = r246
    STOR [TERM] = r246
    STOR [TERM] = r245
    STOR [TERM] = r241
    STOR [TERM] = r240
    STOR [TERM] = r241
    
    STOR [TERM] = r245
    STOR [TERM] = r246
    STOR [TERM] = r246
    STOR [TERM] = r246
    STOR [TERM] = r246
    STOR [TERM] = r246
    STOR [TERM] = r245
    STOR [TERM] = r241
    STOR [TERM] = r240
    STOR [TERM] = r241
    
    STOR [TERM] = r245
    STOR [TERM] = r246
    STOR [TERM] = r246
    STOR [TERM] = r246
    STOR [TERM] = r246
    STOR [TERM] = r246
    STOR [TERM] = r245
    STOR [TERM] = r241
    STOR [TERM] = r240
    STOR [TERM] = r241

    STOR [TERM] = r244

    BRA  [!print_dice]
!line_7
    STOR [TERM] = r245
    STOR [TERM] = r246
    STOR [TERM] = r246
    STOR [TERM] = r246
    STOR [TERM] = r246
    STOR [TERM] = r246
    STOR [TERM] = r245
    STOR [TERM] = r241
    STOR [TERM] = r241
    STOR [TERM] = r241
 
    STOR [TERM] = r245
    STOR [TERM] = r246
    STOR [TERM] = r246
    STOR [TERM] = r246
    STOR [TERM] = r246
    STOR [TERM] = r246
    STOR [TERM] = r245
    STOR [TERM] = r241
    STOR [TERM] = r241
    STOR [TERM] = r241
 
    STOR [TERM] = r245
    STOR [TERM] = r246
    STOR [TERM] = r246
    STOR [TERM] = r246
    STOR [TERM] = r246
    STOR [TERM] = r246
    STOR [TERM] = r245
    STOR [TERM] = r241
    STOR [TERM] = r241
    STOR [TERM] = r241
 
    STOR [TERM] = r245
    STOR [TERM] = r246
    STOR [TERM] = r246
    STOR [TERM] = r246
    STOR [TERM] = r246
    STOR [TERM] = r246
    STOR [TERM] = r245
    STOR [TERM] = r241
    STOR [TERM] = r241
    STOR [TERM] = r241
 
    STOR [TERM] = r245
    STOR [TERM] = r246
    STOR [TERM] = r246
    STOR [TERM] = r246
    STOR [TERM] = r246
    STOR [TERM] = r246
    STOR [TERM] = r245
    STOR [TERM] = r241
    STOR [TERM] = r241
    STOR [TERM] = r241

    BRA  [!check]

#######################################
!print_dice
    LOAD r144=[!dice_w_pips]
    ADD  r142 = PC + 2
    BRA  [!Which_row]
    INC  r223
    BRAL [!print_dice], r223<r222
    MOVI r223=0
    BRA  [!line_7]
    
!Which_row
    LOAD r177 = [r225+dice]
    SUB  r177 = r177 - '1'
    MULT r164 = r223 * 19
    MULT r233 = r177 * 3

    ADD  r146 = r233 + r164
    LOAD r199 = [r146+!dice_w_pips]
    STOR [TERM] = r240
    STOR [TERM] = r241
    STOR [TERM] = r199
    ADD  r146 = r146+1
    LOAD r199 = [r146+!dice_w_pips]
    STOR [TERM] = r199
    ADD  r146 = r146+1
    LOAD r199 = [r146+!dice_w_pips]
    STOR [TERM] = r199
    STOR [TERM] = r241
    STOR [TERM] = r240
    BRAE [!bottom], r223 == r2
    BRANE[!not_bottom], r223 != r2
    STOR [TERM] = r240 
    BRA  [!skip]
!bottom 
    STOR [TERM] = r242
    STOR [TERM] = r241
    STOR [TERM] = r241
    BRA  [!skip]
!not_bottom
    STOR [TERM] = r241
    STOR [TERM] = r240
    STOR [TERM] = r241
!skip
    INC  r225
    BRAL [!Which_row], r225 < r224
    MOVI r155 = 0xa
    STOR [TERM] = r155
    MOVI r225 = 0
    MOVI r199 = 0
    MOVI r146 = 0

    BRA  [r142]
#######################################
!inf
    
    MOVI r171 = 0             # count for die "1"
    MOVI r172 = 0             # count for die "2"
    MOVI r173 = 0             # count for die "3"
    MOVI r174 = 0             # count for die "4"
    MOVI r175 = 0             # count for die "5"
    MOVI r176 = 0             # count for die "6"

    STOR [r160 + count] = r171
    STOR [r161 + count] = r172
    STOR [r162 + count] = r173
    STOR [r163 + count] = r174
    STOR [r164 + count] = r175
    STOR [r165 + count] = r176

    MOVI r159 = 0
    MOVI r77  = 0
    MOVI r78  = 0
    MOVI r79  = 0
    MOVI r225 = 0
    
    MOVI r140 = !enter_str
    ADD  r141 = PC + 2
    BRA  [!print_str]
    MOVI r140 = !CRLF
    ADD  r141 = PC + 2
    BRA  [!print_str]
    LOAD r45 = [KEYB]

    BRA  [!roll_dice]

!print_str
    LOAD r142 = [r140] 
    BRAE [!found_null], r142 == r0
    STOR [TERM] = r142
    INC  r140
    BRA  [!print_str]

!found_null 
    BRA  [r141]

!check
    LOAD r180 = [r159 + dice]
    STOR [TERM] = r180
    SUB  r181 = r180 - '1'

    ADD  r135 = PC + 2
    BRAE [!inc_count_1], r181 == r160
    ADD  r135 = PC + 2
    BRAE [!inc_count_2], r181 == r161
    ADD  r135 = PC + 2
    BRAE [!inc_count_3], r181 == r162
    ADD  r135 = PC + 2
    BRAE [!inc_count_4], r181 == r163
    ADD  r135 = PC + 2
    BRAE [!inc_count_5], r181 == r164
    ADD  r135 = PC + 2
    BRAE [!inc_count_6], r181 == r165

    INC  r159
    BRAL [!check], r159 < r151
    MOVI r159 = 0
    STOR [TERM] = r244
    BRA  [!print_results]

#################################################
!inc_count_1
    INC  r171
    STOR [r160 + count] = r171
    BRA  [r135]
!inc_count_2
    INC  r172
    STOR [r161 + count] = r172
    BRA  [r135]
!inc_count_3
    INC  r173
    STOR [r162 + count] = r173
    BRA  [r135]
!inc_count_4
    INC  r174
    STOR [r163 + count] = r174
    BRA  [r135]
!inc_count_5
    INC  r175
    STOR [r164 + count] = r175
    BRA  [r135]
!inc_count_6
    INC  r176
    STOR [r165 + count] = r176
    BRA  [r135]
#################################################

!print_results
    LOAD r200 = [r78 + count]
    ADD  r5 = r200 + '0'
    STOR [TERM] = r5
    STOR [TERM] = r244
    BRAE [!print_yachtzee], r200 == r170
    BRAE [!print_four_kind], r200 == r169
    BRAE [!check_three], r200 == r168
    ADD  r143 = PC + 2
    BRA  [!check_straight]
    INC  r78
    BRAL [!print_results], r78 < r151
    MOVI r78 = 0
!check_three
    LOAD r201 = [r79 + count]
    BRAE [!print_full_house], r201 == r167
    INC  r79
    BRAL [!check_three], r79 < r151
    MOVI r79 = 0
    BRA  [!print_three_kind]
!check_straight
    MOVI r80 = 0              # 0th die, 1
    MOVI r85 = 5              # 5th die, 6
    LOAD r202 = [r80 + count]
    LOAD r203 = [r85 + count]
    BRAE [!check_2], r202 == r0
    BRAE [!check_5], r203 == r0
    INC  r77
    BRAL [r143], r77 < r151
    MOVI r77 = 0
    BRA  [!print_nothing]
!check_2 
    MOVI r81 = 1              # 1st die, 2
    LOAD r204 = [r81 + count]
    BRAE [!check_3], r204 == r0
!check_3 

!check_4 
!check_5 

!print_yachtzee
    MOVI r140 = !yachtzee_str
    ADD  r141 = PC + 2
    BRA  [!print_str]
    BRA  [!inf]
!print_large_straight
    MOVI r140 = !large_str
    ADD  r141 = PC + 2
    BRA  [!print_str]
    BRA  [!inf]
!print_small_straight
    MOVI r140 = !small_str
    ADD  r141 = PC + 2
    BRA  [!print_str]
    BRA  [!inf]
!print_full_house
    MOVI r140 = !full_str
    ADD  r141 = PC + 2
    BRA  [!print_str]
    BRA  [!inf]
!print_four_kind
    MOVI r140 = !four_str
    ADD  r141 = PC + 2
    BRA  [!print_str]
    BRA  [!inf]
!print_three_kind
    MOVI r140 = !three_str
    ADD  r141 = PC + 2
    BRA  [!print_str]
    BRA  [!inf]
!print_nothing
    MOVI r140 = !nothing_str
    ADD  r141 = PC + 2
    BRA  [!print_str]
    BRA  [!inf]

!yachtzee_str
    "YACHTZEE"
!large_str
    "Large straight"
!small_str
    "Small straight"
!four_str
    "Four of a kind"
!three_str    
    "Three of a kind"
!full_str    
    "Full House"
!nothing_str
    "Nothing of interest"
!enter_str
    0xd 0xa 0xd 0xa "Press the Enter key to roll the dice" 0xd 0xa

!CRLF
    0xd 0xa 0

!dice_w_pips
    "     @@  @ @@ @@ @"
    " @     @     @ @ @"
    "   @    @@ @@ @@ @"