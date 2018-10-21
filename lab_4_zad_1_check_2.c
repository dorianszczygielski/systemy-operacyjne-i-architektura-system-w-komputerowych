#include <stdio.h>
#include "FSM_actions.rl"

int main(void) {

  char result;
  char string[] = ":";
  
  result = parse(string);
  printf("%d \n", result);

return 0;
}
