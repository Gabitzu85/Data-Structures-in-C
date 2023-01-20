#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ex1.h"

int main()
{
  pers *cap=NULL;
  creare(&cap,"Andrei","0785678432","inginer");
  creare(&cap,"Ioana","0759658538","electrician");
  creare(&cap,"Gica","0567854967","farmacist");
  creare(&cap,"Mirel","0557894286","mecanic");
  creare(&cap,"Badea","0674862389","psiholog");
  creare(&cap,"Bartolomeu","0106584957","antrenor");
  printf("Lista initiala: \n\n");
  afisare(cap);

  adauga_dupa(&cap,3);
  introducere_nou(&cap);
  stergere(&cap);

  afisare(cap);
}
