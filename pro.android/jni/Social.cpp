#include "Social.h"
#include <jni.h>
#include <android/log.h>
#include "PluginJniHelper.h"
#include <stdlib.h>

using namespace anysdk::framework;

#define  LOG_TAG    "Social"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG,__VA_ARGS__);

extern "C"{
void Java_com_anysdk_sample_wrapper_nativeSubmitScore(JNIEnv*  env, jobject thiz)
{
	Social::getInstance()->submitScore();
}

void Java_com_anysdk_sample_wrapper_nativeShowLeaderboard(JNIEnv*  env, jobject thiz)
{
	Social::getInstance()->showLeaderboard();
}

void Java_com_anysdk_sample_wrapper_nativeUnlockAchievement(JNIEnv*  env, jobject thiz)
{
	Social::getInstance()->unlockAchievement();
}

void Java_com_anysdk_sample_wrapper_nativeShowAchievements(JNIEnv*  env, jobject thiz)
{
	Social::getInstance()->showAchievements();
}
}


Social* Social::_pInstance = NULL;

Social::Social()
{
	_pSocial = AgentManager::getInstance()->getSocialPlugin();
	setListener();

}

Social::~Social()
{

}

Social* Social::getInstance()
{
    if (_pInstance == NULL) {
        _pInstance = new Social();
    }
    return _pInstance;
}

void Social::purge()
{
    if (_pInstance)
    {
        delete _pInstance;
        _pInstance = NULL;
    }
}

void Social::setListener()
{
	if(!_pSocial) return;

	_pSocial->setListener(this);
}

void Social::submitScore()
{
	if(!_pSocial) return;

	_pSocial->submitScore("friend",1);
}

void Social::showLeaderboard()
{
	if(!_pSocial) return;

	_pSocial->showLeaderboard("friends");
}

void Social::unlockAchievement()
{
	if(!_pSocial) return;

	TAchievementInfo achInfo;
	achInfo["rank"] = "friends";
	_pSocial->unlockAchievement(achInfo);
}

void Social::showAchievements()
{
	if(!_pSocial) return;

	_pSocial->showAchievements();
}


//社交回调函数
void Social::onSocialResult(SocialRetCode code, const char* msg)
{
	switch(code)
	{
	case kScoreSubmitSucceed://提交分数成功回调

		break;
	case kScoreSubmitfail://提交分数失败回调

		break;
	case kAchUnlockSucceed://解锁成F就成功回调

		break;
	case kAchUnlockFail://解锁成就失败回调

		break;
	default:
		break;
	}
}


