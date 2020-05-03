/*
OO Design principles and Design patterns that can be applied to design it:
1. SRP (Single Responsibility Principle):
You should be able to think about the basic classes and their relationship.
2. Composition (Post will have a list of comments, likes)
3. Observer Pattern: to send the notifications
4. Iterator pattern: to iterate in the list of posts or followers
5. Singleton: to create only one/limited instance of Admin
*/


public enum ConnectionInvitationStatus {
  PENDING, ACCEPTED, CONFIRMED, REJECTED, CANCELED
}

public enum AccountStatus {
  ACTIVE, BLOCKED, BANNED, COMPROMISED, ARCHIVED, UNKNOWN
}

public class Address {
  private String streetAddress;
  private String city;
  private String state;
  private String zipCode;
  private String country;
}

/*
Account, Person, Member, and Admin: These classes represent the different people that interact with our system:
*/

// For simplicity, we are not defining getter and setter functions. The reader can

public class Account {
 private String id;
 private String password;
 private AccountStatus status;

 public boolean resetPassword();
}

public abstract class Person {
 private String name;
 private Address address;
 private String email;
 private String phone;

 private Account account;
}

public class Member extends Person {
 private Date dateOfMembership;
 private String headline;
 private byte[] photo;
 private List<Member> memberSuggestions;
 private List<Member> memberFollows;
 private List<Member> memberConnections;
 private List<Company> companyFollows;
 private List<Group> groupFollows;
 private Profile profile;

 public boolean sendMessage(Message message);
 public boolean createPost(Post post);
 public boolean sendConnectionInvitation(ConnectionInvitation invitation);
}

public class Admin extends Person {
 public boolean blockUser(Customer customer);
 public boolean unblockUser(Customer customer);
}

/*
Profile, Experience, etc: A member’s profile will have their job experiences, educations, skills, etc:
*/

public class Profile {
  private String summary;
  private List<Experience> experiences;
  private List<Education> educations;
  private List<Skill> skills;
  private List<Accomplishment> accomplishments;
  private List<Recommendation> recommendations;
  private List<Stat> stats;

  public boolean addExperience(Experience experience);
  public boolean addEducation(Education education);
  public boolean addSkill(Skill skill);
  public boolean addAccomplishment(Accomplishment accomplishment);
  public boolean addRecommendation(Recommendation recommendation);
}

public class Experience {
  private String title;
  private String company;
  private String location;
  private Date from;
  private Date to;
  private String description;
}

/*
Company and JobPosting: Companies can have multiple job postings:
*/

public class Company {
  private String name;
  private String description;
  private String type;
  private int companySize;

  private List<JobPosting> activeJobPostings;
}

public class JobPosting {
  private Date dateOfPosting;
  private String description;
  private String employmentType;
  private String location;
  private boolean isFulfilled;
}

/*
Group, Post, and Message: Members can create posts, send messages, and join groups:
*/
public class Group {
  private String name;
  private String description;
  private int totalMembers;
  private List<Member> members;

  public boolean addMember(Member member);

  public boolean updateDescription(String description);
}

public class Post {
  private String text;
  private int totalLikes;
  private int totalShares;
  private Member owner;
}

public class Message {
  private Member[] sentTo;
  private String messageBody;
  private byte[] media;
}
/*
Search interface and SearchIndex: SearchIndex will implement the Search interface to facilitate searching for members, companies and job postings:
*/
public interface Search {
  public List<Member> searchMember(String name);

  public List<Company> searchCompany(String name);

  public List<JobPosting> searchJob(String title);
}

public class SearchIndex implements Search {
  HashMap<String, List<Member>> memberNames;
  HashMap<String, List<Company>> companyNames;
  HashMap<String, List<JobPosting>> jobTitles;

  public boolean addMember(Member member) {
    if (memberNames.containsKey(member.getName())) {
      memberNames.get(member.getName()).add(member);
    } else {
      memberNames.put(member.getName(), member);
    }
  }

  public boolean addCompany(Company company);

  public boolean addJobPosting(JobPosting jobPosting);

  public List<Member> searchMember(String name) {
    return memberNames.get(name);
  }

  public List<Company> searchCompany(String name) {
    return companyNames.get(name);
  }

  public List<JobPosting> searchJob(String title) {
    return jobTitles.get(title);
  }
}
