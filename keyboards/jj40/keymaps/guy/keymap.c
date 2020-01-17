#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _LOWER  1
#define _RAISE  2
#define _HYPER  3

// Custom Keys
#define ALT_TAB LALT(KC_TAB)
#define KC_CAD LALT(LCTL(KC_DEL))
#define DSK_LEFT LCTL(LWIN(KC_LEFT))
#define DSK_RGHT LCTL(LWIN(KC_RGHT))

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CTRL | Ctrl | GUI  | ALT  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_mit( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT , \
  KC_LCTL, KC_LCTL, KC_LGUI, KC_LALT, MO(_LOWER),  KC_SPC,  MO(_RAISE),   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |     |    \  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |Hyper | Home |PGDWN |PGUP  | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_mit( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,S(KC_NUHS),S(KC_NUBS),_______, _______, KC_PIPE, \
  _______, _______, _______, _______, _______, _______, MO(_HYPER), KC_HOME, KC_PGDOWN, KC_PGUP, KC_END \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |Hyper |             |      | Play | Vol- | Vol+ | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_mit( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, _______, _______, KC_BSLS, \
  _______, _______, _______, _______, MO(_HYPER), _______, _______, KC_MPLY, KC_VOLD, KC_VOLU, KC_MNXT \
),

/* Hyper
 * ,-----------------------------------------------------------------------------------.
 * |RESET |      |      |      |      |      |      |      |      |      |      | CAD  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |BL ON |BL OFF|      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |BLTOGG|BLBRTG|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |DSKLFT|BL_DEC|BL_INC|DSKRGH|
 * `-----------------------------------------------------------------------------------'
 */
[_HYPER] = LAYOUT_planck_mit( \
  RESET  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_CAD , \
  _______, _______, _______, _______, _______, BL_ON  , BL_OFF , _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, BL_TOGG, BL_BRTG, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, DSK_LEFT, BL_DEC, BL_INC, DSK_RGHT \
)
};


uint32_t layer_state_set_user(uint32_t state) {
  switch (biton32(state)) {
    case _RAISE:
        rgblight_setrgb (0xFF,  0x55, 0x00);
        break;
    case _LOWER:
        rgblight_setrgb (0x00,  0x00, 0xFF);
        break;
    case _HYPER:
        rgblight_setrgb (0xFF,  0x00, 0xF4);
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (0x00,  0x000, 0x00);
        break;
    }
  return state;
}

uint16_t key_timer;
bool key_triggered = false;

// Loop
void matrix_scan_user(void) {
  // Empty
};
