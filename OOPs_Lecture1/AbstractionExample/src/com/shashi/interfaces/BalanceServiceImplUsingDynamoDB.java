package com.shashi.interfaces;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;

public class BalanceServiceImplUsingDynamoDB implements BalanceService {

    private HashMap<String, Integer> map = new HashMap<String, Integer>();
    @Override
    public int getBalance(String userId) {
        if (map.containsKey(userId)) {
            return map.get(userId);
        }
        return -1;
    }

    @Override
    public boolean setBalance(String userId, int balance) {
        map.put(userId, balance);

        return true;
    }
}
