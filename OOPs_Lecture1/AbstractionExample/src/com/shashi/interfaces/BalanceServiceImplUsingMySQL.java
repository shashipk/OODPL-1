package com.shashi.interfaces;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.TreeMap;

public class BalanceServiceImplUsingMySQL implements BalanceService {

// map 
    private TreeMap<String, Integer> map = new TreeMap<String, Integer>();

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
