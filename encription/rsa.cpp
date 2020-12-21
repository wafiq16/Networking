    /*
     * C++ Program to Implement the RSA Algorithm
     */
    #include<iostream>
    #include<math.h>
    #include<string.h>
    #include<stdlib.h>

    using namespace std;

    long int p, q, n, t, flag, e[100], d[100], temp[100], j, m[100], en[100], i;
    char msg[100];
    int prime(long int);
    void ce();
    long int cd(long int);
    void encrypt();
    void decrypt();
    int prime(long int pr)
    {
        int i;
        j = sqrt(pr);
        for (i = 2; i <= j; i++)
        {
            if (pr % i == 0)
                return 0;
        }
        return 1;
    }

    int main()
    {
        cout << "\nENTER FIRST PRIME NUMBER\n";
        cin >> p;
        flag = prime(p);
        if (flag == 0)
        {
            cout << "\nWRONG INPUT\n";
            exit(1);
        }
        cout << "\nENTER ANOTHER PRIME NUMBER\n";
        cin >> q;
        flag = prime(q);
        if (flag == 0 || p == q)
        {
            cout << "\nWRONG INPUT\n";
            exit(1);
        }
        cout << "\nENTER MESSAGE\n";
        fflush(stdin);
        cin >> msg;
        for (i = 0; msg[i] != '\0'; i++)
            m[i] = msg[i];
        n = p * q;
        t = (p - 1) * (q - 1);
        ce();
        cout << "\nPOSSIBLE VALUES OF e AND d ARE\n";
        for (i = 0; i < j - 1; i++)
            cout << e[i] << "\t" << d[i] << "\n";
        cout << "\n INITIAL MESSAGE IS\n";
        for (i = 0; m[i] != '\0'; i++)
            printf("dlm int %li || dlm char %c\n", m[i],m[i]);
        encrypt();
        decrypt();
        return 0;
    }

    void ce()
    {
        int k;
        k = 0;
        for (i = 2; i < t; i++)
        {
            if (t % i == 0)
                continue;
            flag = prime(i);
            if (flag == 1 && i != p && i != q)
            {
                e[k] = i;
                flag = cd(e[k]);
                if (flag > 0)
                {
                    d[k] = flag;
                    k++;
                }
                if (k == 99)
                    break;
            }
        }
    cout << "hitung ce" << endl;
    }

    long int cd(long int x)
    {
        long int k = 1;
        while (1)
        {
            k = k + t;
            if (k % x == 0)
                return (k / x);
        }
        cout << "hitung cd" << endl;
    }

    void encrypt()
    {
        long int pt, ct, key = e[1], k, len;
        i = 0;
        len = strlen(msg);
        while (i != len)
        {
            pt = m[i];
            pt = pt - 96;
            k = 1;
            for (j = 0; j < key; j++)
            {
                k = k * pt;
                k = k % n;
            }
            cout << "k = " << k << "keyc = " << key << endl;
            temp[i] = k;
            ct = k + 96;
            en[i] = ct;
            i++;
            cout << " pt = " << pt << endl;
        }
        en[i] = -1;
        cout << "\nTHE ENCRYPTED MESSAGE IS\n";
        for (i = 0; en[i] != -1; i++)
            printf("dlm int %li || dlm char %c\n", en[i],en[i]);
    }

    void decrypt()
    {
        long int pt, ct, key = d[1], k;
        i = 0;
        while (en[i] != -1)
        {
            ct = temp[i];
            k = 1;
            cout << ct << endl;
            for (j = 0; j < key; j++)
            {
                k = k * ct;
                k = k % n;
                // cout << "k = " << k << endl;
            }
            // cout << "k = " << k;
            pt = k + 96;
            m[i] = pt;
            // cout <<" m = "<< m[i]  <<  endl;
            i++;
        }
        cout << "keyd = " << key << endl;
        m[i] = -1;
        cout << "\nTHE DECRYPTED MESSAGE IS\n";
        for (i = 0; m[i] != -1; i++)
            printf("%c", m[i]);
    }