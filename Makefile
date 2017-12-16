#
# Makefile écrit par A. Scheuer
#

# répertoires (console seul, gui, tous)
CNSL_REP = 1 2a 2b 3 4
GUI_REP  = 5 6 7
ALL_REP  = $(CNSL_REP) $(GUI_REP)

# commandes pour énumérer les répertoires
for_rep  = for rep in $(1); do cd $$rep; $(2); cd ..; echo "done $$rep" ; done
my_make  = make -f my.Makefile

console:
	$(call for_rep, $(ALL_REP), $(my_make) $@)

gui:
	$(call for_rep, $(GUI_REP), $(my_make) $@)

doc:
	$(call for_rep, $(ALL_REP), $(my_make) $@)

clean:
	$(call for_rep, $(ALL_REP), $(my_make) $@)

clean_doc: 
	$(call for_rep, $(ALL_REP), $(my_make) $@)

dist:	clean 
	tar -jcf CPOOA_Darmois_This_Scheffler.tbz $(ALL_REP) Makefile *.pdf
