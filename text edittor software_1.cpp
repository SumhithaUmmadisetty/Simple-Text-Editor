#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void main_menu(int message);

int main()
{
    main_menu(0);
    return 0;
}
void main_menu(int message)
{
    system("CLS");
	if(message==0)
		cout<<"welcome!!"<<endl;
	if(message==1)
		cout<<"file successfully created"<<endl;
	if(message==2)
		cout<<"file successfully updated"<<endl;
	if(message==3)
		cout<<"file successfully cleared"<<endl;
	if(message==4)
		cout<<"file successfully deleted"<<endl;
	if(message==6)
		cout<<"file successfully copied"<<endl;
	
	cout<<"MAIN MENU"<<endl<<endl;
	cout<<"1. Create File"<<endl;
	cout<<"2. Add to File"<<endl;
	cout<<"3. Read from File"<<endl;
	cout<<"4. Empty File"<<endl;
	cout<<"5. Delete File"<<endl;
	cout<<"6. Copy File"<<endl;
	cout<<"7. Exit"<<endl;
	cout<<"8. Insert text"<<endl;
	cout<<"9. Replace text"<<endl;
	cout<<"10.Cut"<<endl;
	cout<<"11.Copy"<<endl;
	cout<<"12.Paste"<<endl;
	cout<<"Enter Your Choice: "<<endl;
	int choice = 0;
    string file_name;
    string text;
    string clipboard;
	cin>>choice;
	
	if(choice==1)
	{
		cout<<"\nEnter name of file: ";
		cin.ignore();
		getline(cin, file_name);
		ofstream my_file((file_name+".txt").c_str());
		my_file.close();
		main_menu(1);
		cin>>choice;
	}
	if(choice==2)
	{
		text="";
		cout<<"\nEnter File Name: ";
		cin>>file_name;
		cout<<endl<<"Enter text-\n(Enter 'DONE' to complete)"<<endl;
		ofstream my_file;
		my_file.open((file_name+".txt").c_str(),ios::app);
		string line;
		cin.ignore();
		while(getline(cin,line))
		{
			if(line.size()>=3)
			{
				if(line.substr(line.size()-3)=="DONE")
				{
					text+=line.substr(0, line.size()-3);
					break;
				}
				else
					text+=line+"\n";	
			}
			else
				text+=line+"\n";
		}
	my_file<<text;
	my_file.close();
	main_menu(2);
	cin>>choice;
	}

	if(choice==3)
	{
		text="";
		cout<<"\nEnter Name of File: ";
		cin>>file_name;
		fstream my_file;
		my_file.open((file_name+".txt").c_str());
		while(getline(my_file,text))
		{
			cout<<text<<endl;
		}
		my_file.close();
		char now;
		cout<<"\nEnd of File. Press any key for main menu: ";
		cin>>now;
		main_menu(2);
		cin>>choice;
	}
	if(choice==4)
	{
		cout<<"Enter file name: ";
		cin>>file_name;
		ofstream my_file;
		my_file.open((file_name+".txt").c_str());
		my_file.close();
		main_menu(4);
		cin>>choice;
	}
	if (choice == 5)
    {
        // Delete File
        cout << "Enter file name to delete: ";
        cin >> file_name;
        if (remove((file_name + ".txt").c_str()) != 0)
        {
            cout << "Error deleting file!" << endl;
        }
        else
        {
            cout << "File successfully deleted" << endl;
        }
        main_menu(5);
        cin >> choice;
    }
    if (choice==6)
	{
		text="";
		cout<<"Enter file name to copy from: ";
		cin.ignore();
		getline(cin,file_name);
		fstream my_file((file_name+".txt").c_str());
		string line;
		while(getline(my_file,line))
		{
			text+=line+"\n";
		}
		my_file.close();
		cout<<"\nEnter file name";
	}
	if (choice==7)
		cout<<"exitting. See you later";
	if (choice == 8)
    {
        
        cout << "Enter file name: ";
        cin >> file_name;
        cout << "Enter text to insert:\n";
        cin.ignore();
        getline(cin, text);
        cout << "Enter line number to insert at: ";
        int line_number;
        cin >> line_number;

        ifstream old_file((file_name + ".txt").c_str());
        string line;
        string new_text;
        int current_line = 1;

        while (getline(old_file, line))
        {
            if (current_line == line_number)
            {
                new_text += text + "\n";
            }
            new_text += line + "\n";
            current_line++;
        }

        old_file.close();

        ofstream new_file((file_name + ".txt").c_str());
        new_file << new_text;
        new_file.close();

        cout << "Text successfully inserted" << endl;

        main_menu(8);
        cin >> choice;
    }
    else if (choice == 9)
    {
        
        cout << "Enter file name: ";
        cin >> file_name;
        cout << "Enter text to replace: ";
        string old_text;
        cin.ignore();
        getline(cin, old_text);
        cout << "Enter new text: ";
        string new_text;
        getline(cin, new_text);

        ifstream old_file((file_name + ".txt").c_str());
        string line;
        string updated_text;

        while (getline(old_file, line))
        {
            size_t pos = line.find(old_text);
            if (pos != string::npos)
            {
                line.replace(pos, old_text.length(), new_text);
            }
            updated_text += line + "\n";
        }

        old_file.close();

        ofstream new_file((file_name + ".txt").c_str());
        new_file << updated_text;
        new_file.close();

        cout << "Text successfully replaced" << endl;

        main_menu(9);
        cin >> choice;
    }
    if (choice == 10)
    {
        // Cut text from a file
        cout << "Enter file name: ";
        cin >> file_name;
        cout << "Enter line number to cut: ";
        int line_number;
        cin >> line_number;

        ifstream old_file((file_name + ".txt").c_str());
        string line;
        string new_text;
        int current_line = 1;

        while (getline(old_file, line))
        {
            if (current_line == line_number)
            {
                clipboard = line;
            }
            else
            {
                new_text += line + "\n";
            }
            current_line++;
        }

        old_file.close();

        ofstream new_file((file_name + ".txt").c_str());
        new_file << new_text;
        new_file.close();

        cout << "Text successfully cut to clipboard" << endl;

        main_menu(10);
        cin >> choice;
    }
    else if (choice == 11)
    {
        // Copy text from a file
        cout << "Enter file name: ";
        cin >> file_name;
        cout << "Enter line number to copy: ";
        int line_number;
        cin >> line_number;

        ifstream file_to_copy_from((file_name + ".txt").c_str());
        string line;
        int current_line = 1;

        while (getline(file_to_copy_from, line))
        {
            if (current_line == line_number)
            {
                clipboard = line;
                break;
            }
            current_line++;
        }

        file_to_copy_from.close();

        cout << "Text successfully copied to clipboard" << endl;

        main_menu(11);
        cin >> choice;
    }
    else if (choice == 12)
    {
        // Paste text into a file
        cout << "Enter file name: ";
        cin >> file_name;

        ofstream file_to_paste_into((file_name + ".txt").c_str(), ios::app);
        file_to_paste_into << clipboard << endl;
        file_to_paste_into.close();

        cout << "Text successfully pasted from clipboard" << endl;

        main_menu(12);
        cin >> choice;
    }
    else
    {
        cout << "Invalid choice" << endl;
        cin >> choice;
    }
}
