# Miketronic's userspace

Under developement

# Working On

Getting the standalone userspace to work correctly.

10APR23 error:

Compiling: quantum/keymap_introspection.c                                                          In file included from quantum/keymap_introspection.c:5:
./.build/obj_1upkeyboards_pi40_mit_v1_0_miketronic/src/keymap.c:11:8: error: implicit declaration of function 'LAYOUT_ortho_4x12_wrapper'; did you mean 'LAYOUT_ortho_4x12'? [-Werror=implicit-function-declaration]
   11 |  [0] = LAYOUT_ortho_4x12_wrapper(_WORKMAN)
      |        ^~~~~~~~~~~~~~~~~~~~~~~~~
      |        LAYOUT_ortho_4x12
./.build/obj_1upkeyboards_pi40_mit_v1_0_miketronic/src/keymap.c:11:34: error: '_WORKMAN' undeclared here (not in a function)
   11 |  [0] = LAYOUT_ortho_4x12_wrapper(_WORKMAN)
      |                                  ^~~~~~~~
cc1.exe: all warnings being treated as errors
 [ERRORS]
 |
 |
 |
make: *** [builddefs/common_rules.mk:360: .build/obj_1upkeyboards_pi40_mit_v1_0_miketronic/quantum/keymap_introspection.o] Error 1