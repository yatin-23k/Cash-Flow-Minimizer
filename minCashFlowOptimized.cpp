#include<iostream>
#include<fstream>
#include<vector>
#include<queue>

using namespace std;

priority_queue<pair<int, int>> pqCredit;
priority_queue<pair<int, int>> pqDebit;

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
     // While either queue has some payments
    while(!pqCredit.empty() || !pqDebit.empty()){

         // Get the max credit and debit amounts and their indices
        int maxcredit = pqCredit.top().first, maxdebit = pqDebit.top().first, maxi = pqCredit.top().second, mini = pqDebit.top().second;

        // Pop the top elements from both queues
        pqCredit.pop();
        pqDebit.pop();

        int amount = 0;

        // Check which amount is smaller and adjust accordingly
        if (maxcredit > maxdebit){
            amount = maxdebit;
            pqCredit.push(make_pair(maxcredit-amount, maxi));      
        }
        else if (maxcredit < maxdebit){
            amount = maxcredit;
            pqDebit.push(make_pair(maxdebit-amount, mini));        
        }
        else{
            amount = maxcredit;
        }

        // Print the transaction details
        cout << "Friend " << mini + 1 << " should pay " << amount << " rupees to Friend " << maxi + 1 << "\n";
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
        // Push positive payment[i] in pqCredit and negative payment[i] in pqDebit.
        if(payment[i] > 0){
            pqCredit.push(make_pair(payment[i], i));
        }
        else if(payment[i] < 0){
            pqDebit.push(make_pair(abs(payment[i]), i));
        }
    }

    // Check if there are no payments required
    if(pqCredit.empty() && pqDebit.empty()){
        cout << "No Payments Required \n";
        return;
    }

    // Call the cashflowmin function to minimize cash flow
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