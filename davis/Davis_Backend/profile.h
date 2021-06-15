#include <iostream>
#include <string>
#include <vector>
#include <drogon/drogon.h>

using namespace drogon;
using namespace orm;

namespace davis
{
class profile
{
private:
    std::string mForename, mSurname, mEmail, mUsername, mHashsalt, mPassword, mProfilePic;
    float mLatitude, mLongitude;
    int mAccountId;
public:
    profile(int accountId, const std::string& forename, const std::string& surname, const std::string& email, const std::string& username, 
    const std::string& hashsalt, const std::string& password, const std::string& profilePic, float latitude, float longitude);
    profile(const Row& row);

    const int getAccountId();
    const std::string& getForename();
    const std::string& getSurname();
    const std::string& getEmail();
    const std::string& getUsername();
    const std::string& getHashsalt();
    const std::string& getPassword();
    const std::string& getProfilePic();
    float getLatitude();
    float getLongitude();

    void setForename(const std::string& forename);
    void setSurname(const std::string& surname);
    void setEmail(const std::string& email);
    void setUsername(const std::string& username);
    void setHashsalt(const std::string& hashsalt);
    void setPassword(const std::string& password);
    void setProfilePic(const std::string& profilePic);
    void setLatitude(float latitude);
    void setLongitude(float longitude);
    void setAccountId(int accountID);

    ~profile();
};
}
