set(files "${CMAKE_CURRENT_LIST_DIR}/AutoJoin.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/AntiTaunts.cpp"  
        "${CMAKE_CURRENT_LIST_DIR}/Bot.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/bunnyhop.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/Spam.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/AutoItem.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/Aimbot.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/MiscAimbot.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/AntiAim.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/AntiAntiAim.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/AntiDisguise.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/Backtrack.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/BPExpander.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/DataCenter.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/Misc.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/NavBot.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/Noisemaker.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/Votekicks.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/Warp.cpp")
        
target_sources(cathook PRIVATE ${files})

if (EnableVisuals)
    set(files "${CMAKE_CURRENT_LIST_DIR}/ESP.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/Thirdperson.cpp")
    target_sources(cathook PRIVATE ${files})
endif()
