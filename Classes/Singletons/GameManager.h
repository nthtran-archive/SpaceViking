#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include "Constants\Constants.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include <string>
#include <map>
#include "eplibs\EPResourceManager.h"
#include "eplibs\EPNotificationCenter.h"

class GameManager :	public cocos2d::CCObject 
{
public:
	CC_SYNTHESIZE(bool, isMusicON, IsMusicON);
	CC_SYNTHESIZE(bool, isSoundEffectsON, IsSoundEffectsON);
	CC_SYNTHESIZE(bool, hasPlayerDied, HasPlayerDied);
	CC_SYNTHESIZE(int, killCount, KillCount);

	// Added for Audio
protected:
	bool hasAudioBeenInitialized;
	CocosDenshion::SimpleAudioEngine *soundEngine;

	// retain these 2
	cocos2d::CCDictionary<std::string, cocos2d::CCString *> *listOfSoundEffectFiles;
	map<std::string, bool> *soundEffectsState;

	SceneTypes currentScene;

	CC_SYNTHESIZE(GameManagerSoundState, managerSoundState, ManagerSoundState);
	// check if loading has finished
	CC_SYNTHESIZE(bool, hasFinishedLoading, HasFinishedLoading);
	// loading label
	CC_SYNTHESIZE(cocos2d::CCLabelTTF *, loadingLabel, LoadingLabel);

	//public methods
	GameManager();
	~GameManager();
	static GameManager * sharedGameManager();
	void runSceneWithID(SceneTypes sceneID);
	void openSiteWithLinkType(LinkTypes linkTypeToOpen);
	bool init();
	static void purgeSharedGameManager();
	
	// Added for Audio
	void initAudioAsync();
	void setUpAudioEngine();
	int playSoundEffect(const char *soundEffectKey);
	void stopSoundEffect(int soundEffectID);
	void playBackgroundTrack(const char *trackFileName);
	std::string formatSceneTypeToString(SceneTypes sceneID);
	cocos2d::CCDictionary<std::string, cocos2d::CCString*> *getSoundEffectsListForSceneWithID(SceneTypes sceneID);
	void loadAudioForSceneWithID(SceneTypes sceneID);
	void unloadAudioForSceneWithID(SceneTypes sceneID);
	cocos2d::CCSize getDimensionsOfCurrentScene();
};
#endif