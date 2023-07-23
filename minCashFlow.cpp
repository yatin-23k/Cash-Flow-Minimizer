#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

/*
 * Function to input a matrix of Cash Flows from a text file. 
*/
bool inputMatrix(vector<vector<int>>& cashmatrix) {
    ifstream input_file("cashFlow.txt");
    if (!input_file) {
        cerr << "Error opening file\n";
        return false;
    }
    // n is the number of friends 
    int n;
    input_file >> n;

    // taking cashmatrix input
    for(int i = 0; i < n; i++){
        vector<int> tempvec;
        for(int j = 0; j < n; j++){
            int temp;
            input_file >> temp;
            tempvec.push_back(temp);
        }
        cashmatrix.push_back(tempvec);
    }

    input_file.close();

    return true;
}

/*
 * Function to print the cashmatrix.
*/
void printCashMatrix(vector<vector<int>> cashmatrix) 
{
    cout << "cashmatrix : \n";
    for(int i = 0; i < cashmatrix.size(); i++){
        for(int j = 0; j < cashmatrix[0].size(); j++){
            cout << cashmatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

/*
 * This function minimizes the cash flow among a group of friends.
*/
void cashflowmin(vector<int> &payment)
{
    int m = payment.size();
    while(true){

        int maxcredit = 0, maxdebit = 0, maxi, mini;

        for(int i = 0 ; i < m ; i++){         
            // Finding the friend with the maximum credit value and its index            
            if(payment[i] > maxcredit){           
                maxcredit = payment[i];
                maxi = i;
            }
            // Finding the friend with the maximum debit value and its index  
            if(payment[i] < maxdebit){                
                maxdebit = payment[i];
                mini = i;
            }
        }      

        // If there are no more transactions to be made, break the loop
        if(maxcredit == 0 && maxdebit == 0) break;
        
        // Determine the amount to be transferred between friends
        int temp = min(abs(maxdebit), maxcredit);

        // Update the payment values
        payment[maxi] -= temp;
        payment[mini] += temp;

        // Print the transaction details
        cout << "Friend " << mini + 1 << " paid " << temp << " rupees to Friend " << maxi + 1 << "\n";                    
    }
}

/*
 * This function calculates the net payments for each friend based on a cash matrix,
 * and then calls the cashflowmin function to minimize cash flow among friends.
 */
void netpayment(vector<vector<int>> &cashmatrix)
{
    int m = cashmatrix.size();
    vector<int> payment(m, 0);

    // Calculate the net payment for each friend
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
           payment[i] += cashmatrix[j][i] - cashmatrix[i][j];
        }     
    }

    // Minimize cash flow among friends
    cashflowmin(payment);
}

int main()
{
    vector<vector<int>> cashmatrix;
    
    if (!inputMatrix(cashmatrix)) return 0;

    printCashMatrix(cashmatrix);
 
    netpayment(cashmatrix);

    return 0;
}