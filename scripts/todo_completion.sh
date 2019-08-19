_todo_autocompleter()
{
  if [ "${#COMP_WORDS[@]}" = "2" ]; then
    COMPREPLY=($(compgen -W "item priority" "${COMP_WORDS[1]}"))
  fi
  
  if [ "${#COMP_WORDS[@]}" = "3" ]; then
    COMPREPLY=($(compgen -W "add remove" "${COMP_WORDS[2]}"))
    return
  fi
  
  if [ "${#COMP_WORDS[@]}" = "3" ]; then
    COMPREPLY=($(compgen -W "add remove" "${COMP_WORDS[2]}"))
    return
  fi
}

complete -F _todo_autocompleter todo 
