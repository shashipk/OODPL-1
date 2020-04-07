package com.shashi.interfaces;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;

interface BalanceService {

    int getBalance(String userId);

    boolean setBalance(String userId, int balance);

}

