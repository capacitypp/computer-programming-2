/*
 * 作成者			: 佐野和輝
 * 日付				: 2016年6月17日
 * プログラムの内容	: Foodクラスの宣言
 */
#ifndef ___Class_Food
#define ___Class_Food

#include <iostream>

class Food {
private:
	std::string name;	/* 食べ物の名前 */
	float GI;			/* GI値 */
	float carbon;		/* 炭水化物 */
	float calorie;		/* カロリー */
	float fat;			/* 脂質 */
	float protein;		/* タンパク質 */

public:
	Food() {}
	Food(std::string name, float GI, float carbon, float calorie, float fat, float protein) : name(name), GI(GI), carbon(carbon), calorie(calorie), fat(fat), protein(protein) {}
	/* アクセッサ */
	std::string getName() const { return name; }
	float getGI() const { return GI; }
	float getCarbon() const { return carbon; }
	float getCalorie() const { return calorie; }
	float getFat() const { return fat; }
	float getProtein() const { return protein; }
};

#endif

