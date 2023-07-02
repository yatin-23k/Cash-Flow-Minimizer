#include<bits/stdc++.h>
using namespace std;

void cashFlowMin (vector<int> &payment)
{
    int m = payment.size();
    
    while (true) {

        int maxcredit = 0, maxdebit = 0, maxi, mini;

        for (int i = 0; i < m; i++) {                      //finding max credit value and index
            if (payment[i] > maxcredit) {
                maxcredit = payment[i];
                maxi = i;
            }
        }               
        
        for (int i = 0; i < m; i++) {                     // finding max debit value and index
            if (payment[i] < maxdebit) {
                maxdebit = payment[i];
                mini = i;
            }
        }

        if (maxcredit == 0 && maxdebit == 0) {
            break;
        }

        int temp = min(abs(maxdebit), maxcredit);

        payment[maxi] -= temp;
        payment[mini] += temp;

        cout << "Friend " << mini + 1 << " paid " << temp << " rupees to Friend " << maxi + 1 << "\n";
    }
}

void netPayment (vector<vector<int>> &cashmatrix)
{
    int m = cashmatrix.size();
    vector<int> payment(m, 0);
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            payment[i] += cashmatrix[j][i] - cashmatrix[i][j];
        }
    }

    cashFlowMin(payment);
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> cashmatrix;
    
    for (int i = 0; i < n; i++) {
        vector<int> tempvec;
        
        for (int j = 0; j < n; j++) {            
            int temp;
            cin >> temp;
            tempvec.push_back(temp);            
        }
        
        cashmatrix.push_back(tempvec);
    }
    
    cout << cashmatrix.size() << "\n";
    
    netPayment(cashmatrix);
    
    return 0;
}