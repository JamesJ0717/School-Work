#include <stdio.h>

int fuckit(int);


int main(void)
{
  int f = 0;
  scanf("%d", &f);

  printf("here %d", fuckit(f));
}

int fuckit(int x)
{
  printf("DEBUG");
  return(x * fuckit(x + 1));
}
