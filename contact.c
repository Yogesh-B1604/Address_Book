#include <stdio.h>
#include "contact.h"
#include "populate.h"
#include <string.h>
void contact_found(AddressBook *addressBook,int i){
 			printf("contact found ! \n");
                        printf("%s \t",addressBook->contacts[i].name);
                        printf("%s \t",addressBook->contacts[i].phone);
                        printf("%s \n",addressBook->contacts[i].email);

}

void listContacts(AddressBook *addressBook) 
{
	printf("\n--- Contact List ---\n");
	printf("Name \t\t Mobile No. \t Mail Id\n");
	for(int i=0,j=1;i<(addressBook->contactCount),j<=(addressBook->contactCount);i++,j++){
	printf("%d.%s\t%s\t%s\n",
			j,addressBook->contacts[i].name,
			addressBook->contacts[i].phone,
			addressBook->contacts[i].email);
	}
}

void initialize(AddressBook *addressBook) 
{
  //populateAddressBook(addressBook);
  FILE *fptr=fopen("contact.txt","r");
  if(fptr==NULL){
	  printf("failed to open file.");
  }
  fscanf(fptr,"%d",&addressBook->contactCount);
  for(int i=0;i<(addressBook->contactCount);i++){
	  fscanf(fptr," %[^\t] %s %s",
		addressBook->contacts[i].name,
		addressBook->contacts[i].phone,
		addressBook->contacts[i].email);
  }
  fclose(fptr);


}



void saveAndExit(AddressBook *addressBook) {
  	FILE *fptr;
	fptr=fopen("contact.txt","w");
	if(fptr==NULL){
		printf("failed to open file");
	}
	fprintf(fptr,"%d\n",addressBook->contactCount);
	for(int i=0;i<(addressBook->contactCount);i++){                    
		fprintf(fptr,"%s\t%s\t%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
}
printf("\ncontacts saved successfully!\n");
fclose(fptr);
}


void createContact(AddressBook *addressBook)
{
	printf("\nEnter name: ");
	scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);
	printf("Enter phone No. : ");
	scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].phone);
	printf("Enter Mail id : ");
	scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].email);
	printf("\nContact Added Successfully!\n");
	addressBook->contactCount++;

}

void searchContact(AddressBook *addressBook) 
{
	char nametofind[25];
	int flag=0;
	printf("Enter the name to be searched : ");
	scanf(" %[^\n]",nametofind);
	for(int i=0;i<(addressBook->contactCount);i++){
	if(strcmp(nametofind,addressBook->contacts[i].name)==0){
			contact_found(addressBook,i);
	flag=1;
	}
			}
	if(flag==0){
	printf("Contact not found !\n");
  }
}

void editContact(AddressBook *addressBook)
{
	char nametoedit[30];
	int flag=0,choice;
	printf("Enter the contact name to be edited : ");
	scanf(" %[^\n]",nametoedit);
	for(int i=0;i<(addressBook->contactCount);i++){
	if(strcmp(nametoedit,addressBook->contacts[i].name)==0){
		contact_found(addressBook,i);
		printf("What Do you want to edit ?\n");
		printf("1.Name\n2.phone\n3.Email\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:printf("Enter New Name : ");
			       scanf(" %[^\n]",addressBook->contacts[i].name);
			       printf("\nName edited successfully.\n");
			       break;
			case 2:printf("Enter New Phone No. : ");
                               scanf(" %[^\n]",addressBook->contacts[i].phone);
			       printf("\nPhone No. edited successfully.\n");
                               break;
			case 3:printf("Enter New Email : ");
                               scanf(" %[^\n]",addressBook->contacts[i].email);
                               printf("\nEmail edited successfully.\n");
			       break;
			default:
			       printf("Invalid Input , Enter value from 1 to 3.\n");
			       break;
		}
		flag=1;
	}
	}
	if(flag==0){
		printf("Contact not found.\n");
	}

	    
}

void deleteContact(AddressBook *addressBook)
{
   char nametodelete[30];
   int flag=0;
   printf("Enter the contact Name to be Deleted : ");
   scanf(" %[^\n]",nametodelete);
   for(int i=0;i<(addressBook->contactCount);i++){
        if(strcmp(nametodelete,addressBook->contacts[i].name)==0){
                contact_found(addressBook,i);
		for(int j=i;j<(addressBook->contactCount);j++){
			addressBook->contacts[j]=addressBook->contacts[j+1];
		}
		printf("\nContact Deleted Successfully!\n\n");
		addressBook->contactCount--;
		flag=1;
	}
   }
   if(flag==0){
	   printf("Contact not found.\n");
   }
}

