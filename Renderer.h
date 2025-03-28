#ifndef RENDERER_H
#define RENDERER_H

#include <QVulkanWindow>
#include <vector>
#include <unordered_map>
#include "Camera.h"
#include "Triangle.h"
#include "Cube.h"
#include "House.h"
#include "Door.h"
#include "Input.h"
#include "TriangleSurface.h"
#include "VisualObject.h"

class Renderer : public QVulkanWindowRenderer
{
public:
    Renderer(QVulkanWindow *w, bool msaa = false);

    // * These two functions are set for visibility, I hope this isn't inefficient.
    /*
     * scales, moves cam, and changes perspective.
     */
    void setPlayerInHouse();
     /* These two functions are set for visibility, I hope this isn't inefficient.
     *
     *  scales the player down, and moves player inside the house.
     */
    void setCameraInHouse();

    void HouseLogic(); //The () ran that uses the two above functions.
    void WinningLogic();

    QVector3D doorPos;   // Finding door position
    QVector3D playerPos;   // Finding player position

    void hasPassedThroughDoor(); // USED function for a door bool

    // Initializes the Vulkan resources needed,
    // the buffers
    // vertex descriptions for the shaders
    // making the shaders, etc
    void initResources() override;

    //Set up resources - only MVP-matrix for now:
    void initSwapChainResources() override;

    //Empty for now - needed since we implement QVulkanWindowRenderer
    void releaseSwapChainResources() override;

    //Release Vulkan resources when program ends
    //Called by Qt
    void releaseResources() override;

    //Render the next frame
    void startNextFrame() override;

    //Get Vulkan info - just for fun
    void getVulkanHWInfo();

    std::vector<VisualObject*>& getObjects() { return mObjects; }
    std::unordered_map<std::string, VisualObject*>& getMap() { return mMap; }

protected:

    //Creates the Vulkan shader module from the precompiled shader files in .spv format
    VkShaderModule createShader(const QString &name);

	void setModelMatrix(QMatrix4x4 modelMatrix);

	void setRenderPassParameters(VkCommandBuffer commandBuffer);

    //The ModelViewProjection MVP matrix
    QMatrix4x4 mProjectionMatrix;
    //Rotation angle of the triangle
    float mRotation{ 0.0f };

    //Vulkan resources:
    QVulkanWindow* mWindow{ nullptr };
    QVulkanDeviceFunctions* mDeviceFunctions{ nullptr };

    VkDeviceMemory mBufferMemory{ VK_NULL_HANDLE };
    VkBuffer mBuffer{ VK_NULL_HANDLE };

    VkDescriptorPool mDescriptorPool{ VK_NULL_HANDLE };
    VkDescriptorSetLayout mDescriptorSetLayout{ VK_NULL_HANDLE };
    VkDescriptorSet mDescriptorSet[QVulkanWindow::MAX_CONCURRENT_FRAME_COUNT]{ VK_NULL_HANDLE };

    VkPipelineCache mPipelineCache{ VK_NULL_HANDLE };
    VkPipelineLayout mPipelineLayout{ VK_NULL_HANDLE };
    VkPipeline mPipeline1{ VK_NULL_HANDLE };
    VkPipeline mPipeline2{ VK_NULL_HANDLE };

private:
    friend class VulkanWindow;
    int Pickups = 0;
    int maxPickups = 7; //added for easier debug and testing.
    int pickupsCollected = 0;

    bool isWin = false;
    bool isOpen = false;
    bool hasPassedThrough = false;
    bool alreadyThrough = false;
    bool enemyTouched = false;
    bool alreadyLost=false;

    Triangle mTriangle;
    Cube mCube;
    Cube Enemy;
    Cube* Win;
    Cube* Player;
    House* House;
    Door* Door;

    void resetGame();

    Input* mInput;
    TriangleSurface mSurface;
    VisualObject mVisualObject;
    std::vector<VisualObject*> mObjects;
    std::unordered_map<std::string, VisualObject*> mMap;    // alternativ container

    void createBuffer(VkDevice logicalDevice,
                      const VkDeviceSize uniAlign, VisualObject* visualObject,
                      VkBufferUsageFlags usage=VK_BUFFER_USAGE_VERTEX_BUFFER_BIT);

    Camera mCamera;
    class VulkanWindow* mVulkanWindow{ nullptr };
};

#endif // RENDERER_H
