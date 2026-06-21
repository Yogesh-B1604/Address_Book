#include <stdio.h>
#include "contact.h"
#include "populate.h"

int main() 
{ 
       int choice;
       AddressBook var;
       initialize(&var);
       do{
	      printf("\n--- AddressBook Menu ---\n");
              printf("\n1.Add contact.");
              printf("\n2.Edit contact.");
              printf("\n3.Search contact.");
              printf("\n4.Delete contact");
              printf("\n5.list contact.");
              printf("\n6.Save contact.");
              printf("\n7.Exit");
              printf("\nEnter your choice (1-7): ");
              scanf("%d",&choice);
              switch (choice)
              {
              case 1:createContact(&var);
                     break;
	      case 2:editContact(&var);
		     break;
	      case 3:searchContact(&var);
                     break;
	      case 4:deleteContact(&var);
                     break;
	      case 5:listContacts(&var);
                     break;
	      case 6:saveAndExit(&var);
                     break;
	      case 7:printf("Exiting AddressBook ,Thankyou!\n");
                     break;
              default:
                     printf("Invalid input,Enter number from 1 to 7.\n");
                     break;
              }
       }while(choice!=7);
       return 0;
}
