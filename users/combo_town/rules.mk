
SRC += combo_town.c

ifeq ($(strip $(RELEASE_GATE_ENABLE)), yes)
  SRC += release_gate.c
endif
