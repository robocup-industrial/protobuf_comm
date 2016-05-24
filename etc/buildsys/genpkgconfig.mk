#*****************************************************************************
#                 Makefile Build System for Fawkes: Boost bits
#                            -------------------
#   Created on Thu Apr 12 18:07:23 2012
#   Copyright (C) 2012 by Tim Niemueller, AllemaniACs RoboCup Team
#
#*****************************************************************************
#
#   This program is free software; you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation; either version 2 of the License, or
#   (at your option) any later version.
#
#*****************************************************************************

ifndef __buildsys_config_mk_
$(error config.mk must be included before genpkgconfig.mk)
endif

ifndef __buildsys_genpkgconfig_mk_
__buildsys_genpkgconfig_mk_ := 1

ifneq ($(PKGCONFIG_all),)
  TARGETS_all += $(PKGCONFIG_all)
endif

$(PKGCONFDIR)/%.pc: %.pc
	$(eval BUILT_PARTS += $@)
	$(SILENT) mkdir -p $(PKGCONFDIR)
	$(SILENT) mkdir -p $(@D)
	$(SILENTSYMB) echo -e "$(INDENT_PRINT)[PKC] $(PARENTDIR)$(TBOLDGRAY)$(subst $(SRCDIR)/,,$<)$(TNORMAL)"
	$(SILENT) mkdir -p $(dir $(subst ..,__,$@))
	$(SILENT) sed \
		-e 's/@VERSION@/$(PROTOBUF_COMM_VERSION)/g' \
		-e 's|@EXEC_INCDIR@|$(EXEC_INCDIR)|g' \
		$< >$@

endif # __buildsys_genpkgconfig_mk_
