#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Texture
{
public:
    explicit Texture(const string &fileName) : m_FileName(fileName), m_Id(arc4random_uniform(INT_MAX)) {}

    const string description() const
    {
        return "<" + m_FileName + " id" + to_string(m_Id) + ">";
    }
    ~Texture()
    {
        cout << "Destructing " << description() << endl;
    }
    // other texture manipulation methods
private:
    const string m_FileName;
    const int m_Id;
};

class Sprite
{
public:
    Sprite(const Texture *texture) : m_Texture(texture) {
        cout << "Constructing sprite with texture: " << m_Texture->description() << endl;
    }

    void setPositionSize(int x, int y, int width, int height)
    {
        // set position and size
        m_X = x;
        m_Y = y;
        m_Width = width;
        m_Height = height;
    }

    void render()
    {
        // draw sprite
        cout << "Rendering sprite with texture: " << m_Texture->description() << endl;
    }

private:
     int m_Width;
     int m_Height;
     int m_X;
     int m_Y;

    const Texture *m_Texture;
};

class SpriteFactory
{
    public:
        Sprite* makeSprite(const string &fileName){
            auto it = m_SpritePool.find(fileName);
            if(it != m_SpritePool.end()){
                return it->second;
            }else{

            }
        }
    private:
        unordered_map<string, Sprite*> m_SpritePool;
};



int main()
{
    // create a list of sprite objects
    vector<Sprite*> sprites;
    const int numSprites = 10;
    const string textureFile = "spaceship.png";

    for (int i = 0; i < numSprites; ++i)
    {
        auto sprite = new Sprite(10, 10, i * 10, i * 10, textureFile);
        sprites.push_back(sprite);
    }

    // draw all sprites
    for (auto &sprite : sprites)
    {
        sprite->render();
    }

    // cleanup
    for (auto &sprite : sprites)
    {
        delete(sprite);
    }

    return 0;
}
