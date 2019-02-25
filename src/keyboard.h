#ifndef KEYBOARD_H
#define KEYBOARD_H
#include "agents.h"
#include "graphics.h"

enum keyboard_mode {
  NORMAL,
  INSERT,
  SELECT
};

enum keyboard_commands {
  KEYB_CMD_EMPTY,
  KEYB_CMD_CHANGE,
  KEYB_CMD_DELETE,
  KEYB_CMD_INSERT,
  KEYB_CMD_PASTE,
  KEYB_CMD_QUIT,
  KEYB_CMD_RELOAD,
  KEYB_CMD_YANK
};

typedef struct _Keyboard Keyboard;
typedef struct _Normal_buffer Normal_buffer;

struct _Keyboard {
 int mode; 
 Ui_graphics* uig;
 void (*key_act_mode[3])(Keyboard* keyb, int enc_key);
 Normal_buffer* norm_buff;
};

struct _Normal_buffer {
  int multiplier;
  int cmd_id;
  int arg;
};

void keyboard_setup(Keyboard* keyb);

void keyboard_ui_ptr(Keyboard* keyb, Ui_graphics* uig);

void keyboard_set_mode(Keyboard* keyb, int mode);

void keyboard_action(Keyboard* keyb, int key, int mod);

void keyboard_mode_normal(Keyboard* keyb, int enc_key);
void keyboard_mode_insert(Keyboard* keyb, int enc_key);
void keyboard_mode_select(Keyboard* keyb, int enc_key);

int keyboard_key_to_alpha(int enc_key);

Normal_buffer* keyboard_make_norm_buff(void);
int keyboard_num_to_norm_buff(Normal_buffer* norm_buff, int num);
int keyboard_cmd_to_norm_buff(Normal_buffer* norm_buff, int cmd);
int keyboard_cat_num(int* to_int, int num);
void keyboard_clr_norm_buffer(Keyboard* keyb);


#endif
