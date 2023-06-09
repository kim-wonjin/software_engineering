#pragma once
#include "Member.h"
#include <vector>
#include <string>

using namespace std;

class Recruitment;

class CompanyMember : public Member
{
public:
	CompanyMember();

	CompanyMember(int user_type, string name, string businessId, string id, string password)
		: Member(user_type, name, businessId, id, password)
	{ }

    void createNewRecruitment(Recruitment* newRecruitment);
    std::vector<Recruitment*> getRecruitmentList() { return recruitmentList; }
private:
    std::vector<Recruitment*> recruitmentList;
};
