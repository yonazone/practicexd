# Case
Note: Notice that
we’re careful to put the most explicit matches first and the most general match last. This is important
because the casewill execute the first match it finds, not the best match. If we put the `*)` first, it would always be matched, regardless of what was input.

Note: Note that the ;;before esacis optional. Unlike C programming, where leaving out a break is poor
programming practice, leaving out the final ;;is no problem if the last case is the default because no
other cases will be considered.
