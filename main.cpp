// File: main.cpp
// Purpose: Entry point for the vending machine system. Handles user interaction and invokes appropriate methods on VM_1 or VM_2.
// Notes:
// - VM_1 supports float-based operations.
// - VM_2 supports int-based operations.
// - Both use EFSM and Strategy pattern under the hood.

#include <iostream>
#include "model/VM_1.h"
#include "model/VM_2.h"
#include "factory/VM1Factory.h"
#include "factory/VM2Factory.h"

using namespace std;

void clearscreen()
{
    cout << string(50, '\n');
}

int main()
{
    clearscreen();

    cout << "Welcome to the Smart Vending Machine System\n";
    cout << "Select VM type:\n";
    cout << "1. Vending Machine 1 (float-based)\n";
    cout << "2. Vending Machine 2 (int-based)\n";
    cout << "Choice: ";

    int vm_choice;
    cin >> vm_choice;

    AbstractFactory *factory = nullptr;
    VM_1 *vm1 = nullptr;
    VM_2 *vm2 = nullptr;

    if (vm_choice == 1)
    {
        factory = new VM1Factory();
        vm1 = new VM_1(factory);
    }
    else if (vm_choice == 2)
    {
        factory = new VM2Factory();
        vm2 = new VM_2();
    }
    else
    {
        cout << "Invalid choice. Exiting...\n";
        return 1;
    }

    char ch;
    float x, v, p;
    int n;

    cout << "\nVending Machine-" << vm_choice << " Menu\n";
    cout << "0. create(price)\n1. coin(value)\n2. sugar()\n3. chocolate()/coffee()\n4. cappuccino()\n"
            "5. insert_cups(n)\n6. set_price(price)\n7. cancel()\n8. card(value)\nq. quit\n";

    int op_count = 0;
    ch = '1';
    while (ch != 'q')
    {
        cout << "\n-----------------------------\n";
        cout << "Operation Count: " << op_count << endl;
        cout << "Select Operation (0–8 or q): ";
        cin >> ch;

        switch (ch)
        {
        case '0':
            cout << "Enter price: ";
            cin >> p;
            if (vm1)
                vm1->create(p);
            else
                vm2->CREATE(static_cast<int>(p));
            break;
        case '1':
            cout << "Enter coin value: ";
            cin >> v;
            if (vm1)
                vm1->coin(v);
            else
                vm2->COIN(static_cast<int>(v));
            break;
        case '2':
            if (vm1)
                vm1->sugar();
            else
                vm2->SUGAR();
            break;
        case '3':
            if (vm1)
                vm1->chocolate();
            else
                vm2->COFFEE(); // coffee = default drink in VM_2
            break;
        case '4':
            if (vm1)
                vm1->cappuccino();
            else
                vm2->COFFEE(); // cappuccino is not supported separately in VM_2
            break;
        case '5':
            cout << "Enter cup count: ";
            cin >> n;
            if (vm1)
                vm1->insert_cups(n);
            else
                vm2->InsertCups(n);
            break;
        case '6':
            cout << "Enter new price: ";
            cin >> p;
            if (vm1)
                vm1->set_price(p);
            else
                vm2->SetPrice(static_cast<int>(p));
            break;
        case '7':
            if (vm1)
                vm1->cancel();
            else
                vm2->CANCEL();
            break;
        case '8':
            cout << "Enter card value: ";
            cin >> x;
            if (vm1)
                vm1->card(x);
            else
                vm2->COIN(static_cast<int>(x)); // VM_2 assumes card same as COIN
            break;
        case 'q':
            break;
        default:
            cout << "Invalid operation.\n";
            continue;
        }

        ++op_count;
    }

    delete vm1;
    delete vm2;
    delete factory;
    return 0;
}
