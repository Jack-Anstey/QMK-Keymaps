/*
Hello! This is the custom firmware that I am running on my keyboard. I wanted to be able to have a small 75% board without sacrificing
too many conviences that I enjoyed when using my 100% board (I'm looking at you excel charts). 
To do this I have rebound the basic functions of some keys (like print screen now being play/pause for media) and clicking the volume pot now
puts your computer to sleep (it is super hard to do this on accident). I have two separate layers: one function layer to put the board into
boot loader mode and to get back to those previously remapped keys and another where holding caps lock lets you access a hidden numpad.

This also has a RGB matrix with the color purple.

Enjoy!

V1.1
*/

/*
Sidenote, if you try to reflash and its not updating, make sure to clear the keyboards EEPROM.
Use the bootmagic escape; unplug the board, press and hold escape as you plug it back in, then release and unplug/replug.
Should fix it in a jiffy
*/

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the RESET key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+ESC. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_MPLY,          KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        MO(2),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT(
        RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR,          KC_SLEP,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_TRNS,          KC_HOME,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_INS,
        _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          S(KC_INS),
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, RGB_TOG,
        _______, _______, _______,                            _______,                            _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT
    ),

    [2] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_TRNS,          _______,
        _______, _______, KC_CAPS, _______, _______, _______, _______, KC_7,    KC_8,    KC_9,    _______, _______, _______, _______,          _______,
        _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_CAPS, _______, _______, KC_4,    KC_5,    KC_6,    _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    _______,          _______, _______, _______,
        _______, _______, _______,                            KC_0,                               _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT
    ),

    //this empty layer is so that this keymap will work with VIA
    [3] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),


};

static uint16_t key_timer;

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch(biton32(layer_state)){
            case 1: // layer 1 (fn)
                if (clockwise){
                    tap_code16(KC_BRIU); //Brightness up and down
                } else{
                    tap_code16(KC_BRID);
                }
                break;
            case 2: // layer 2 (caps lock)
                if (clockwise) {
                    tap_code16(C(KC_TAB)); //cycle through tabs in web browser
                } else {
                    tap_code16(S(C(KC_TAB)));
                }
                break;
            case 3: // layer 3 (undefined currently)
                if (clockwise) {
                    tap_code16(KC_BRMU); // MacOS Brightness up and down
                } else {
                    tap_code16(KC_BRMD);
                }
                break;
            default:
                // if (clockwise) { //basic version
                //     tap_code16(KC_VOLU); //volume up and down for layer 0
                // } else {
                //     tap_code16(KC_VOLD);
                // }
                // break;

                if (clockwise) {
                    tap_code16(KC_VOLU);
                    if (timer_elapsed(key_timer) < 100) {
                        tap_code16(KC_VOLU); // if less than 100ms have passed, hit vol down twice.
                        tap_code16(KC_VOLU);
                        key_timer = timer_read();
                    } else {
                        key_timer = timer_read(); // do nothing if 100ms or more have passed
                    }
                } else {
                    tap_code16(KC_VOLD);
                    if (timer_elapsed(key_timer) < 100) {
                        tap_code16(KC_VOLD); // if less than 100ms have passed, hit vol down twice.
                        tap_code16(KC_VOLD);
                        key_timer = timer_read();
                    } else {
                        key_timer = timer_read(); // do nothing if 100ms or more have passed
                    }
                }
                break;
        }
    }
    return false; //gets rid of the default volume behavior
}
#endif // ENCODER_ENABLE

// RGB LED layout

// led number, function of the key

//  67, Side led 01    0, ESC      6, F1       12, F2       18, F3       23, F4       28, F5       34, F6       39, F7       44, F8       50, F9       56, F10      61, F11      66, F12      69, Prt       Rotary(Mute)   68, Side led 12
//  70, Side led 02    1, ~        7, 1        13, 2        19, 3        24, 4        29, 5        35, 6        40, 7        45, 8        51, 9        57, 0        62, -_       78, (=+)     85, BackSpc   72, Del        71, Side led 13
//  73, Side led 03    2, Tab      8, Q        14, W        20. E        25, R        30, T        36, Y        41, U        46, I        52, O        58, P        63, [{       89, ]}       93, \|        75, PgUp       74, Side led 14
//  76, Side led 04    3, Caps     9, A        15, S        21, D        26, F        31, G        37, H        42, J        47, K        53, L        59, ;:       64, '"                    96, Enter     86, PgDn       77, Side led 15
//  80, Side led 05    4, Sh_L     10, Z       16, X        22, C        27, V        32, B        38, N        43, M        48, ,<       54, .<       60, /?                    90, Sh_R     94, Up        82, End        81, Side led 16
//  83, Side led 06    5, Ct_L     11,Win_L    17, Alt_L                              33, SPACE                              49, Alt_R    55, FN                    65, Ct_R     95, Left     97, Down      79, Right      84, Side led 17
//  87, Side led 07                                                                                                                                                                                                        88, Side led 18
//  91, Side led 08    

/*
RGB Matrix
*/
void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  
  int rgbColors[]  = {148,0,211};
  switch(get_highest_layer(layer_state)){  // special handling per layer
          case 1:  //layer one
                rgb_matrix_set_color_all(0,0,0); //makes all other things dark before individual keys are lit
                rgb_matrix_set_color(94, rgbColors[0], rgbColors[1], rgbColors[2]);
                rgb_matrix_set_color(95, rgbColors[0], rgbColors[1], rgbColors[2]);
                rgb_matrix_set_color(97, rgbColors[0], rgbColors[1], rgbColors[2]);
                rgb_matrix_set_color(79, rgbColors[0], rgbColors[1], rgbColors[2]); //arrows | up, down, left, right

                rgb_matrix_set_color(9, rgbColors[0], rgbColors[1], rgbColors[2]); //a
                rgb_matrix_set_color(21, rgbColors[0], rgbColors[1], rgbColors[2]); //d
                rgb_matrix_set_color(15, rgbColors[0], rgbColors[1], rgbColors[2]); //s

                rgb_matrix_set_color(11, rgbColors[0], rgbColors[1], rgbColors[2]); //windows key (left)

                rgb_matrix_set_color(69, rgbColors[0], rgbColors[1], rgbColors[2]); //print (nice)

                rgb_matrix_set_color(0, rgbColors[0], rgbColors[1], rgbColors[2]); //esc for reset

                rgb_matrix_set_color(72, rgbColors[0], rgbColors[1], rgbColors[2]); //Buttons below the knob
                rgb_matrix_set_color(75, rgbColors[0], rgbColors[1], rgbColors[2]);
                rgb_matrix_set_color(86, rgbColors[0], rgbColors[1], rgbColors[2]); 
                rgb_matrix_set_color(82, rgbColors[0], rgbColors[1], rgbColors[2]); 

                rgb_matrix_set_color(67, rgbColors[0], rgbColors[1], rgbColors[2]); 
                rgb_matrix_set_color(70, rgbColors[0], rgbColors[1], rgbColors[2]); 
                rgb_matrix_set_color(73, rgbColors[0], rgbColors[1], rgbColors[2]); 
                rgb_matrix_set_color(76, rgbColors[0], rgbColors[1], rgbColors[2]); 
                rgb_matrix_set_color(80, rgbColors[0], rgbColors[1], rgbColors[2]);
                rgb_matrix_set_color(83, rgbColors[0], rgbColors[1], rgbColors[2]);
                rgb_matrix_set_color(87, rgbColors[0], rgbColors[1], rgbColors[2]);
                rgb_matrix_set_color(91, rgbColors[0], rgbColors[1], rgbColors[2]); //left side leds

                rgb_matrix_set_color(68, rgbColors[0], rgbColors[1], rgbColors[2]); 
                rgb_matrix_set_color(71, rgbColors[0], rgbColors[1], rgbColors[2]); 
                rgb_matrix_set_color(74, rgbColors[0], rgbColors[1], rgbColors[2]); 
                rgb_matrix_set_color(77, rgbColors[0], rgbColors[1], rgbColors[2]); 
                rgb_matrix_set_color(81, rgbColors[0], rgbColors[1], rgbColors[2]);
                rgb_matrix_set_color(84, rgbColors[0], rgbColors[1], rgbColors[2]);
                rgb_matrix_set_color(88, rgbColors[0], rgbColors[1], rgbColors[2]);
                rgb_matrix_set_color(92, rgbColors[0], rgbColors[1], rgbColors[2]); //right side leds
                
          break;
          case 2: //layer 2
                rgb_matrix_set_color_all(0,0,0); //makes all other things dark before individual keys are lit
                rgb_matrix_set_color(94, rgbColors[0], rgbColors[1], rgbColors[2]);
                rgb_matrix_set_color(95, rgbColors[0], rgbColors[1], rgbColors[2]);
                rgb_matrix_set_color(97, rgbColors[0], rgbColors[1], rgbColors[2]);
                rgb_matrix_set_color(79, rgbColors[0], rgbColors[1], rgbColors[2]); //arrows | up, down, left, right

                rgb_matrix_set_color(69, rgbColors[0], rgbColors[1], rgbColors[2]); //print (nice)

                rgb_matrix_set_color(41, rgbColors[0], rgbColors[1], rgbColors[2]);
                rgb_matrix_set_color(46, rgbColors[0], rgbColors[1], rgbColors[2]);
                rgb_matrix_set_color(52, rgbColors[0], rgbColors[1], rgbColors[2]);

                rgb_matrix_set_color(42, rgbColors[0], rgbColors[1], rgbColors[2]);
                rgb_matrix_set_color(47, rgbColors[0], rgbColors[1], rgbColors[2]);
                rgb_matrix_set_color(53, rgbColors[0], rgbColors[1], rgbColors[2]);

                rgb_matrix_set_color(43, rgbColors[0], rgbColors[1], rgbColors[2]);
                rgb_matrix_set_color(48, rgbColors[0], rgbColors[1], rgbColors[2]);
                rgb_matrix_set_color(54, rgbColors[0], rgbColors[1], rgbColors[2]);

                rgb_matrix_set_color(33, rgbColors[0], rgbColors[1], rgbColors[2]); //numpad (space is 0, don't forget)

                rgb_matrix_set_color(9, rgbColors[0], rgbColors[1], rgbColors[2]); //a
                rgb_matrix_set_color(21, rgbColors[0], rgbColors[1], rgbColors[2]); //d
                rgb_matrix_set_color(15, rgbColors[0], rgbColors[1], rgbColors[2]); //s
                rgb_matrix_set_color(14, rgbColors[0], rgbColors[1], rgbColors[2]); //w
                rgb_matrix_set_color(26, rgbColors[0], rgbColors[1], rgbColors[2]); //f

                rgb_matrix_set_color(67, rgbColors[0], rgbColors[1], rgbColors[2]); 
                rgb_matrix_set_color(70, rgbColors[0], rgbColors[1], rgbColors[2]); 
                rgb_matrix_set_color(73, rgbColors[0], rgbColors[1], rgbColors[2]); 
                rgb_matrix_set_color(76, rgbColors[0], rgbColors[1], rgbColors[2]); 
                rgb_matrix_set_color(80, rgbColors[0], rgbColors[1], rgbColors[2]);
                rgb_matrix_set_color(83, rgbColors[0], rgbColors[1], rgbColors[2]);
                rgb_matrix_set_color(87, rgbColors[0], rgbColors[1], rgbColors[2]);
                rgb_matrix_set_color(91, rgbColors[0], rgbColors[1], rgbColors[2]); //left side leds

                rgb_matrix_set_color(68, rgbColors[0], rgbColors[1], rgbColors[2]); 
                rgb_matrix_set_color(71, rgbColors[0], rgbColors[1], rgbColors[2]); 
                rgb_matrix_set_color(74, rgbColors[0], rgbColors[1], rgbColors[2]); 
                rgb_matrix_set_color(77, rgbColors[0], rgbColors[1], rgbColors[2]); 
                rgb_matrix_set_color(81, rgbColors[0], rgbColors[1], rgbColors[2]);
                rgb_matrix_set_color(84, rgbColors[0], rgbColors[1], rgbColors[2]);
                rgb_matrix_set_color(88, rgbColors[0], rgbColors[1], rgbColors[2]);
                rgb_matrix_set_color(92, rgbColors[0], rgbColors[1], rgbColors[2]); //right side leds


          break;
          default: //layer 0
              rgb_matrix_set_color_all(rgbColors[0], rgbColors[1], rgbColors[2]);
              break;
          break;
  }
} 