/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>


#define U_NP KC_NO // key is not present
#define U_NA KC_NO // present but not available for use
#define U_NU KC_NO // available but not used

enum layers { BASE, MBO, MEDIA, NAV, MOUSE, SYM, NUM, FUN };

#if defined MIRYOKU_CLIPBOARD_FUN
#define U_RDO KC_AGIN
#define U_PST KC_PSTE
#define U_CPY KC_COPY
#define U_CUT KC_CUT
#define U_UND KC_UNDO
#elif defined MIRYOKU_CLIPBOARD_MAC
#define U_RDO SCMD(KC_Z)
#define U_PST LCMD(KC_V)
#define U_CPY LCMD(KC_C)
#define U_CUT LCMD(KC_X)
#define U_UND LCMD(KC_Z)
#elif defined MIRYOKU_CLIPBOARD_WIN
#define U_RDO C(KC_Y)
#define U_PST C(KC_V)
#define U_CPY C(KC_C)
#define U_CUT C(KC_X)
#define U_UND C(KC_Z)
#else
#define U_RDO KC_AGIN
#define U_PST S(KC_INS)
#define U_CPY C(KC_INS)
#define U_CUT S(KC_DEL)
#define U_UND KC_UNDO
#endif


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
    
    KC_F13,KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,              KC_Y,              KC_U,              KC_I,              KC_O,              KC_P, XXXXXXX,
    KC_F14,LGUI_T(KC_A),      LALT_T(KC_S),      LCTL_T(KC_D),      LSFT_T(KC_F),      KC_G,              KC_H,              LSFT_T(KC_J),      LCTL_T(KC_K),      LALT_T(KC_L),      LGUI_T(KC_SCLN), KC_QUOT,
    KC_F15,KC_Z,              ALGR_T(KC_X),      KC_C,              KC_V,              KC_B,              KC_N,              KC_M,              KC_COMM,           ALGR_T(KC_DOT),    KC_SLSH, XXXXXXX,
                    LT(MEDIA, KC_ESC), LT(NAV, KC_SPC),   LT(MOUSE, KC_TAB), LT(SYM, KC_ENT),   LT(NUM, KC_BSPC),  LT(FUN, KC_DEL)

  ),
  [SYM] = LAYOUT_split_3x6_3(
    XXXXXXX, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,       U_NA,    U_NA,    U_NA,    U_NA,    XXXXXXX, XXXXXXX,
    XXXXXXX, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,       U_NA,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
    XXXXXXX, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,       U_NA,    U_NA,    U_NA,    KC_ALGR, U_NA, XXXXXXX,
        KC_LPRN, KC_RPRN, KC_UNDS, U_NA,    U_NA,    U_NA          
  ),        

  [NUM] = LAYOUT_split_3x6_3(       
    XXXXXXX, KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,       U_NA,    U_NA,    U_NA,    U_NA,    XXXXXXX, XXXXXXX,
    XXXXXXX, KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,        U_NA,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
    XXXXXXX, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS,       U_NA,    U_NA,    U_NA,    KC_ALGR, U_NA, XXXXXXX,
                                KC_DOT,  KC_0,    KC_MINS, U_NA,    U_NA,    U_NA          
  ),        

  [NAV] = LAYOUT_split_3x6_3(       
    RESET, XXXXXXX,   U_NA,    U_NA,    U_NA,    U_NA,          U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND, XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA,          KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
    XXXXXXX, U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA,          KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END, XXXXXXX,
                                U_NA,    U_NA,    U_NA,          KC_ENT,  KC_BSPC, KC_DEL
  ),        
  [MOUSE] = LAYOUT_split_3x6_3(     
    XXXXXXX, XXXXXXX,   U_NA,    U_NA,    U_NA,    U_NA,          U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND, XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA,          U_NU,    KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX,
    XXXXXXX, U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA,          U_NU,    KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX,
                                U_NA,    U_NA,    U_NA,          KC_BTN1, KC_BTN3, KC_BTN2
  ),        
  [MEDIA] = LAYOUT_split_3x6_3(     
    XXXXXXX, XXXXXXX,   U_NA,    U_NA,    U_NA,    U_NA,          RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA,          U_NU,    KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX,
    XXXXXXX, U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA,          U_NU,    U_NU,    U_NU,    U_NU,    U_NU, XXXXXXX,
                                U_NA,    U_NA,    U_NA,          KC_MSTP, KC_MPLY, KC_MUTE
  ),        
  [MBO] = LAYOUT_split_3x6_3(       
    XXXXXXX, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_TRNS,       KC_TRNS, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
    XXXXXXX, U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND,         U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND, XXXXXXX,
                                 KC_BTN2, KC_BTN3, KC_BTN1, KC_BTN1, KC_BTN3, KC_BTN2
  ),
  [FUN] = LAYOUT_split_3x6_3(
    XXXXXXX, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR, U_NA,    U_NA,    U_NA,    U_NA,    XXXXXXX, XXXXXXX,
    XXXXXXX, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SLCK, U_NA,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
    XXXXXXX, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, U_NA,    U_NA,    U_NA,    KC_ALGR, U_NA, XXXXXXX,
        KC_APP,  KC_SPC,  KC_TAB,  U_NA,    U_NA,    U_NA    
  )
};


bool encoder_update_user(uint8_t index, bool clockwise) {
 
if (clockwise) {
  tap_code16(C(KC_Y));
} else {
  tap_code16(C(KC_Z));
}
 
    return true;
}