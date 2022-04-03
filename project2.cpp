
#include<iostream>
#include<unistd.h>

struct emp {

	std::string name,id,address;
	long int contact;
	float salary;
};

emp e[500];
int total = 0;

void  enterData() {

	int choice;
	std::cout << "How many Employees data you want to enter ?" << std::endl;
	std::cin >> choice;
	std::cout << "\n";

	for(int i=total; i < total+choice; i++) {

		std::cout << "Enter data of employee "<< i+1 << std::endl;
		
		std::cout << "Enter Name 	 : " ;
		std::cin >> e[i].name;

		std::cout << "Enter ID 	 : " ;
		std::cin >> e[i].id;
		
		std::cout << "Enter Address 	 : " ;
		std::cin >> e[i].address;
		
		std::cout << "Enter Contact No : " ;
		std::cin >> e[i].contact;
		
		std::cout << "Enter Salary 	 : " ;
		std::cin >> e[i].salary;
	}
	total= total+choice;
}
void displayData() {

	if(total == 0)
		std::cout << "No records" << std::endl;
	else {

		for(int i = 0; i<total; i++) {

			std::cout << "Data of employee "<< i+1 << std::endl;
	
			std::cout << "\x1b[33mName		ID		Address			Contact			Salary\x1b[0m " << std::endl;
			std::cout << "-----------------------------------------------------------------------------------------" << std::endl;
			std::cout << e[i].name << "\t\t" << e[i].id << "\t\t" <<e[i].address << "\t\t\t" << e[i].contact << "\t\t" << e[i].salary << std::endl;
			std::cout << "\n";
		}
	}
}
void searchData() {
        
	if(total == 0)
                std::cout << "No records" << std::endl;
	else {
		std::string id;
		std::cout << "Enter Id of employee for search" << std::endl;
		std::cin >> id;

		for(int i = 0; i< total; i++) {

			if(id == e[i].id) {

			std::cout << "\x1b[33mName              ID              Address                 Contact                 Salary\x1b[0m " << std::endl;
                        std::cout << "-----------------------------------------------------------------------------------------" << std::endl;
                        std::cout << e[i].name << "\t\t" << e[i].id << "\t\t" <<e[i].address << "\t\t\t" << e[i].contact << "\t\t" << e[i].salary << std::endl;
                        std::cout << "\n";
			break;
			}
			if(i==total-1)
				std::cout << "No record found" << std::endl;
		}
	}
}
void updateData() {

        if(total == 0)
                std::cout << "No records" << std::endl;
	else {
		
		std::string id;
		std::cout << "Enter Id of employee for Update" << std::endl;
		std::cin >> id;

		for(int i = 0; i< total; i++) {

                        if(id == e[i].id) {
			
			std::cout << "Previous Data:" << std::endl;
			std::cout << "\x1b[33mName              ID              Address                 Contact                 Salary\x1b[0m " << std::endl;
                        std::cout << "-----------------------------------------------------------------------------------------" << std::endl;
                        std::cout << e[i].name << "\t\t" << e[i].id << "\t\t" << e[i].address << "\t\t\t" << e[i].contact << "\t\t" << e[i].salary << std::endl;
                        std::cout << "\n";
 
			std::cout << "Enter New Data:" << std::endl;
		
			std::cout << "Enter Name : " ;
        	        std::cin >> e[i].name;
	
        	        std::cout << "Enter ID : " ;
                	std::cin >> e[i].id;

  	                std::cout << "Enter Address : " ;
        	        std::cin >> e[i].address;

                	std::cout << "Enter Contact No : " ;
         	        std::cin >> e[i].contact;

                	std::cout << "Enter Salary : " ;
     			std::cin >> e[i].salary;

			break;
                        }
                        if(i==total-1)
                                std::cout << "No record found" << std::endl;
                }
	}
}

void deleteData() {

	if(total == 0)
		std::cout << "No records present in the system" << std::endl;
	else {
		int choice;
		std::cout << "press 0 to delete full record" << std::endl;
		std::cout << "press 1 to delete specific record" << std::endl;

		std::cin >> choice ;

		if(choice == 0) {
				
			total = 0;
			std::cout << "All record deleted successfully" << std::endl;
		
		} else if(choice == 1) {
		
		std::string id;
                std::cout << "Enter Id of employee for delete" << std::endl;
                std::cin >> id;

		for(int i = 0; i<total; i++) {
			
			if(id == e[i].id) {
			
				for(int j=i; j < total; j++) {

					e[j].name = e[j+1].name;
					e[j].id = e[j+1].id;
					e[j].address = e[j+1].address;
					e[j].contact = e[j+1].contact;
					e[j].salary = e[j+1].salary;
					total--;
					break;
					}
					if(i == total-1)
						std::cout << "No such record found" << std::endl;
				}
			}
		}
	}	
}
int main() {

	std::string username,password;

	std::cout << "\t\x1b[34mEmployee Management System\x1b[0m" << std::endl;
	std::cout << "\t    Sign Up For Admin\n" << std::endl;

	std::cout << "Create Username : " ;
	std::cin >> username;

	std::cout << "Create Password : " ;
	std::cin >> password;

	std::cout << "\nYour Id is creating Plz wait...." << std::endl;
	sleep(3);
	std::cout << "\x1b[36mYour Id Created Successfully\x1b[0m" << std::endl;

	start:
	std::string username1,password1;
	std::cout << "\n\x1b[34mLogin\x1b[0m " << std::endl;
	std::cout << "Enter Username : " ;
	std::cin >> username1;

	std::cout << "Enter Password : " ;
	std::cin >> password1;

	if(username == username1 && password == password1) {

		do {
			std::cout << "\x1b[34m1) Enter Data	2) Display Data	     3) Search Data	4) Update Data	   5) Delete Data   6) Logout   7) Exit\x1b[0m" << std::endl;

			int choice;
			std::cout << "Enter Choice" << std::endl;
			std::cin >> choice;

			switch(choice) {

				case 1:
					enterData();
					break;
				case 2:
					displayData();
					break;
				case 3:
					searchData();
					break;
				case 4:
					updateData();
					break;
				case 5:
					deleteData();
					break;
				case 6:
					std::cout << "\x1b[36mYou have been successfully logged out\x1b[0m" << std::endl;
					goto start;
					break;
				case 7:
					exit(1);
					break;
				default:
					std::cout << "Wrong Choice" << std::endl;
			}

		} while(1);	
	
	} else if(username != username1 && password != password1) {
	
		std::cout << "\x1b[31mYou entered incorrect username & password.. Please enter correct details\n\x1b[0m"<< std::endl;
		goto start;

	} else if(username != username1) {

		std::cout << "\x1b[31mYou entered incorrect username.. Please Enter correct Username\n\x1b[0m" << std::endl;
		goto start;

	} else if(password != password1)  {
	
		std::cout << "\x1b[31m You entered incorrect password.. Please enter correct Password\n\x1b[0m"<< std::endl;
		goto start;
	}	
	return 0;	
}
