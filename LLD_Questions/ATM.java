/*
We can use following Design patterns to Design ATM
1. Facade (as discussed in the lecture)
2. State (The ATM can be in multiple states like has_card_state, no_card_state, etc.)
sample code : https://ideone.com/zg3uxV
3. Strategy (for the logic of cash dispense)
4. Chain of Responsibility (will be discussed in the lecture) :
 https://www.journaldev.com/1617/chain-of-responsibility-design-pattern-in-java
5. Command Pattern (every transaction can be considered as a command)

------------------------------------------------------------------
In this code, only facade pattern and SOLID Principles are used
------------------------------------------------------------------
*/

public enum TransactionType {
  BALANCE_INQUIRY, DEPOSIT_CASH, DEPOSIT_CHECK, WITHDRAW, TRANSFER
}

public enum TransactionStatus {
  SUCCESS, FAILURE, BLOCKED, FULL, PARTIAL, NONE
}

public class Address {
  private String streetAddress;
  private String city;
  private String state;
  private String zipCode;
  private String country;
}

// For simplicity, we are not defining getter and setter functions. The reader can

public class Card {
  private String cardNumber;
  private String customerName;
  private Date cardExpiry;
  private int pin;

}

public class Account {
  private int accountNumber;
  private double totalBalance;
  private double availableBalance;

  public double getAvailableBalance();
}

public class SavingAccount extends Account {
}

public class CurrentAccount extends Account {
  private double withdrawLimit;

}


// Just a simple bank class, although it's not required
public class Bank {
  private List<Account> bankAccounts;
  private String name;
  private String bankCode;

// It will have a lot of methods like checking balance, verifyATMCard etc.

}

// This class communicates with bank, ATM class will have an instance of BankManager
public class BankManager {

  private Bank bank; // The bank with which it communicates

  public boolean verifyATMCard(Card card, String pin)
  public int getAvailableBalance(String accountNo)
  // other methods like updating account balance after a transaction

}

// The facade class:  The ATM will have different components like keypad, screen, etc.
public class ATM {
  private int atmID;
  private Address location;
  private CashDispenser cashDispenser;
  private Keypad keypad;
  private Screen screen;
  private Printer printer;
  private CheckDeposit checkDeposit;
  private CashDeposit cashDeposit;
  private BankManager bankManager;

  /*
  It will have a lot of methods like insert_A_card, insert_pin, insert_amount etc.
  These methods will be called by the actors (Users or Operrators).
  ATM will be delegating those methods to the other classes like to dispense the cash, it will call
  the method of CashDispenser
  */

}

public class CashDispenser {
  private int totalFiveDollarBills;
  private int totalTwentyDollarBills;

  public boolean dispenseCash(double amount);
  public boolean canDispenseCash();
}

public class Keypad {
  public String getInput();
}

public class Screen {
  public boolean showMessage(String message);
  public TransactionType getInput();
}

public class Printer {
  public boolean printReceipt(Transaction transaction);
}

public abstract class DepositSlot {
  private double totalAmount;
  public double getTotalAmount();
}

public class CheckDepositSlot extends DepositSlot {
  public double getCheckAmount();
}

public class CashDepositSlot extends DepositSlot {
  public double receiveDollarBill();
}

/*
Transaction and its subclasses: Customers can perform different transactions on the ATM, these classes encapsulate them:
*/

public abstract class Transaction {
  private int transactionId;
  private Date creationTime;
  private TransactionStatus status;
  public boolean makeTransation();
}

public class BalanceInquiry extends Transaction {
  private int accountId;
  public double getAccountId();
}

public abstract class Deposit extends Transaction {
  private double amount;
  public double getAmount();
}

public class CheckDeposit extends Deposit {
  private String checkNumber;
  private String bankCode;

  public String getCheckNumber();
}

public class CashDeposit extends Deposit {
  private double cashDepositLimit;
}

public class Withdraw extends Transaction {
  private double amount;
  public double getAmount();
}

public class Transfer extends Transaction {
  private int destinationAccountNumber;
  public int getDestinationAccount();
}
