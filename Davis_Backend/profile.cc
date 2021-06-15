#include "profile.h"

namespace davis
{
    profile::profile(int accountID, const std::string &forename, const std::string &surname, const std::string &email, const std::string &username,
    const std::string &hashsalt, const std::string &password, const std::string &profilePic, float latitude, float longitude) :
        mAccountId{accountID}, mForename{forename}, mSurname{surname}, mEmail{email}, mUsername{username}, 
            mHashsalt{hashsalt}, mPassword{password}, mProfilePic{profilePic}, mLatitude{latitude}, mLongitude{longitude}
    {
    }

    profile::profile(const Row& r)
    {
        
        for(const auto& fields : r)
        {
             if(std::string(fields.name()).find("accountid") != std::string::npos)
                 mAccountId= fields.as<int>();
             else if(std::string(fields.name()).find("username") != std::string::npos)
                 mUsername = fields.as<std::string>();
             else if(std::string(fields.name()).find("forename") != std::string::npos)
                mForename = fields.as<std::string>();
             else if(std::string(fields.name()).find("surname") != std::string::npos)
                mSurname = fields.as<std::string>();
             if(std::string(fields.name()).find("password") != std::string::npos)
                 mPassword = fields.as<std::string>();
             else if(std::string(fields.name()).find("profilepic") != std::string::npos)
                mProfilePic = fields.as<std::string>();
             else if(std::string(fields.name()).find("latitude") != std::string::npos)
                mLatitude = fields.as<float>();
             else if(std::string(fields.name()).find("longitude") != std::string::npos)
                mLongitude = fields.as<float>();
             else if(std::string(fields.name()).find("hashsalt") != std::string::npos)
                mHashsalt = fields.as<std::string>();
             else if(std::string(fields.name()).find("email") != std::string::npos)
                mEmail = fields.as<std::string>();
 
        }
    }

    const int profile::getAccountId()
    {
        return mAccountId;
    }

    const std::string &profile::getForename()
    {
        return mForename;
    }
    const std::string &profile::getSurname()
    {
        return mSurname;
    }
    const std::string &profile::getEmail()
    {
        return mEmail;
    }
    const std::string &profile::getUsername()
    {
        return mUsername;
    }
    const std::string &profile::getHashsalt()
    {
        return mHashsalt;
    }
    const std::string &profile::getPassword()
    {
        return mPassword;
    }
    const std::string &profile::getProfilePic()
    {
        return mProfilePic;
    }
    float profile::getLatitude()
    {
        return mLatitude;
    }
    float profile::getLongitude()
    {
        return mLongitude;
    }
    void profile::setForename(const std::string &forename)
    {
        mForename = forename;
    }
    void profile::setSurname(const std::string &surname)
    {
        mSurname = surname;
    }
    void profile::setEmail(const std::string &email)
    {
        mEmail = email;
    }
    void profile::setUsername(const std::string &username)
    {
        mUsername = username;
    }
    void profile::setHashsalt(const std::string &hashsalt)
    {
        mHashsalt = hashsalt;
    }
    void profile::setPassword(const std::string &password)
    {
        mPassword = password;
    }
    void profile::setProfilePic(const std::string &profilePic)
    {
        mProfilePic = profilePic;
    }

    void profile::setLatitude(float latitude)
    {
        mLatitude = latitude;
    }

    void profile::setLongitude(float longitude)
    {
        mLongitude = longitude;
    }

    void profile::setAccountId(int accountId)
    {
        mAccountId = accountId;
    }
}