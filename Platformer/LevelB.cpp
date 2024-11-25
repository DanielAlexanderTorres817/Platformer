/**
* Author: Daniel Torres
* Assignment: Platformer
* Date due: 2024-11-25, 11:59pm
* I pledge that I have completed this assignment without
* collaborating with anyone else, in conformance with the
* NYU School of Engineering Policies and Procedures on
* Academic Misconduct.
**/

#include "LevelB.h"
#include "Utility.h"

#define LEVEL_WIDTH 40
#define LEVEL_HEIGHT 16

constexpr char PLAYER_IDLE_FILEPATH[] = "assets/player/Idle.png",
PLAYER_RUN_FILEPATH[] = "assets/player/Run.png",
PLATFORM_FILEPATH[] = "assets/tilesheet.png",
ENEMY_FILEPATH[] = "assets/enemy/Idle.png";

unsigned int LEVEL_B_DATA[] =
{
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 10, 11, 12,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  4,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     7,  8,  8,  8,  8,  8,  8,  8,  8,  9,  0,  0,  7,  8,  8,  8,  9,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  4,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    14, 15, 15, 15, 15, 15, 15, 15, 15, 16,  0,  0, 14, 15, 15, 15, 16,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    14, 15, 15, 15, 15, 15, 15, 15, 15, 16,  0,  0, 14, 15, 15, 15, 16,  0,  0,  0,  0,  0,  0,  0,  0,  0,  7,  8,  8,  8,  8,  8,  8,  9,  0,  0,  0,  0,  0,  0,
    14, 15, 15, 15, 15, 15, 15, 15, 15, 16,  0,  0, 14, 15, 15, 15, 16,  0,  0,  0,  0,  0,  0,  0,  0,  0, 14, 15, 15, 15, 15, 15, 15, 16,  0,  0,  0,  0,  0,  0,
    14, 15, 15, 15, 15, 15, 15, 15, 15, 16,  0,  0, 14, 15, 15, 15, 16,  0,  0,  0,  0,  0,  0,  0,  0,  0, 14, 15, 15, 15, 15, 15, 15, 16,  0,  0,  0,  0,  0,  0
};





// ------ CAMERA ADJUST ---------//
float B_left_bound_offset = -(LEVEL_WIDTH * 0.5) / 2.0f;
float B_top_bound_offset = (LEVEL_HEIGHT * 0.5) / 2.0f;
glm::vec3 B_view_offset(B_left_bound_offset, B_top_bound_offset, 0.0f);

GLuint  B_font_texture_id;


LevelB::~LevelB()
{
    delete[] m_game_state.enemies;
    delete    m_game_state.player;
    delete    m_game_state.map;
    Mix_FreeChunk(m_game_state.jump_sfx);
    Mix_FreeMusic(m_game_state.bgm);
}

void LevelB::initialise()
{
    B_font_texture_id = Utility::load_texture("assets/font1.png");

    GLuint map_texture_id = Utility::load_texture(PLATFORM_FILEPATH);
    m_game_state.map = new Map(LEVEL_WIDTH, LEVEL_HEIGHT, LEVEL_B_DATA, map_texture_id, 0.5f, 7, 6);

    GLuint player_idle_texture_id = Utility::load_texture(PLAYER_IDLE_FILEPATH);
    GLuint player_walk_texture_id = Utility::load_texture(PLAYER_RUN_FILEPATH);

    std::vector<GLuint> player_texture_ids = {
        player_idle_texture_id,   // IDLE spritesheet
        player_walk_texture_id,   // WALK spritesheet
        //player_dead_texture_id, //DEAD spritesheet
        //player_attack_texture_id //attack spritesheet
    };


    std::vector<std::vector<int>> player_animations = {
        {0, 1, 2, 3, 4, 5, 6, 7},       // IDLE animation frames
        {0, 1, 2, 3, 4, 5, 6, 7},       // RUN animation frames
        //{0, 1, 2, 3},                   // DEAD animation frames
        //{0, 1, 2, 3, 4, 5, 6, 7, 8}     // ATTACK animation frames
    };

    glm::vec3 acceleration = glm::vec3(0.0f, -5.905f, 0.0f);

    m_game_state.player = new Entity(
        player_texture_ids,        // texture id
        2.5f,                      // speed
        acceleration,              // acceleration
        4.5f,                      // jumping power
        player_animations,         // animation index sets
        0.0f,                      // animation time
        8,                         // animation frame amount
        0,                         // current animation index
        8,                         // animation column amount
        1,                         // animation row amount
        0.15f,                     // width
        1.5f,                      // height
        PLAYER
    );

    m_game_state.player->set_scale(glm::vec3(1.5f, 1.5f, 1.0f));
    m_game_state.player->set_position(-B_view_offset + (glm::vec3(-9.5f, 3.0f, 0.0f)));



    /**
     Enemies' stuff */
    GLuint enemy_texture_id = Utility::load_texture(ENEMY_FILEPATH);
    std::vector<GLuint> enemy_texture_ids = {

        Utility::load_texture("assets/enemy/Idle.png"), // IDLE spritesheet
        Utility::load_texture("assets/enemy/Run.png"),  // WALK spritesheet


    };

    m_game_state.enemies = new Entity[2];
    std::vector<std::vector<int>> enemy_animations = {

        {0, 1, 2, 3, 4, 5, 6,},          // IDLE animation frames
        {0, 1, 2, 3, 4, 5, 6, 7},        // RUN animation frames


    };

    for (int i = 0; i < 2; i++)
    {
        m_game_state.enemies[i] = Entity(enemy_texture_ids, enemy_animations, 1.5f, 0.25f, 1.5f, ENEMY, GUARD, IDLING);
        m_game_state.enemies[i].set_scale(glm::vec3(1.5f, 1.5f, 1.0f));
    }


    m_game_state.enemies[0].set_position(B_view_offset + glm::vec3(5.5f, 1.0f, 0.0f));
    m_game_state.enemies[0].set_movement(glm::vec3(0.0f));
    m_game_state.enemies[0].set_acceleration(glm::vec3(0.0f, -5.81f, 0.0f));
    m_game_state.enemies[0].set_ai_type(JUMPER);

    m_game_state.enemies[1].set_position(-B_view_offset + glm::vec3(5.75f, 1.0f, 0.0f));
    m_game_state.enemies[1].set_movement(glm::vec3(0.0f));
    m_game_state.enemies[1].set_acceleration(glm::vec3(0.0f, -9.81f, 0.0f));
    m_game_state.enemies[1].set_ai_type(JUMPER);
    m_game_state.enemies[1].set_jumping_power(7.0f);
    m_game_state.enemies[1].face_left();


    /**
     BGM and SFX
     */
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);

    m_game_state.bgm = Mix_LoadMUS("assets/bgm.mp3");
    Mix_PlayMusic(m_game_state.bgm, -1);
    Mix_VolumeMusic(MIX_MAX_VOLUME / 2);

    m_game_state.jump_sfx = Mix_LoadWAV("assets/jump.wav");
}

void LevelB::update(float delta_time)
{
    m_game_state.player->update(delta_time, m_game_state.player, m_game_state.enemies, 2, m_game_state.map);

    for (int i = 0; i < ENEMY_COUNT; i++) {
        m_game_state.enemies[i].update(delta_time, m_game_state.player, NULL, 0, m_game_state.map);
        Entity& enemy = m_game_state.enemies[i];


        if (m_game_state.player->check_collision(&enemy) &&
            m_game_state.player->get_position().y > enemy.get_position().y &&
            m_game_state.player->get_velocity().y < 0)
        {
            m_game_state.enemies[i].deactivate();
        }
        else if (enemy.m_is_active && m_game_state.player->check_collision(&enemy))
        {
            m_game_state.subtract = true;
        }
    
    }
    if (m_game_state.player->get_position().y < -7.0f) {
        m_game_state.next_scene_id = 3;
        m_game_state.change = true;
    }
}


void LevelB::render(ShaderProgram* g_shader_program)
{
    Utility::draw_text(g_shader_program, B_font_texture_id, "------->", 0.5f, 0.0f, -B_view_offset + glm::vec3(-3.75f, 2.5f, 0.0f));
    Utility::draw_text(g_shader_program, B_font_texture_id, "GO DOWN!", 0.31f, 0.0f, -B_view_offset + glm::vec3(7.5f, 2.5f, 0.0f));
    m_game_state.map->render(g_shader_program);
    m_game_state.player->render(g_shader_program);
    for (int i = 0; i < 2; i++)
        m_game_state.enemies[i].render(g_shader_program);


}
