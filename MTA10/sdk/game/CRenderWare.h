/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto v1.0
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        sdk/game/CRenderWare.h
*  PURPOSE:     RenderWare engine interface
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#ifndef __CRENDERWARE
#define __CRENDERWARE

#include "RenderWare.h"
#include <list>

class CD3DDUMMY;
class CSHADERDUMMY;

typedef void (*PFN_WATCH_CALLBACK) ( CSHADERDUMMY* pContext, CD3DDUMMY* pD3DDataNew, CD3DDUMMY* pD3DDataOld );

#define MAX_ATOMICS_PER_CLUMP   128

class CRenderWare {
    public:
    virtual void                ModelInfoTXDAddTextures     ( std::list < RwTexture* >& textures, unsigned short usModelID, bool bMakeCopy = true, std::list < RwTexture* >* pReplacedTextures = NULL, std::list < RwTexture* >* pAddedTextures = NULL, bool bAddRef = true ) = 0;
    virtual void                ModelInfoTXDRemoveTextures  ( std::list < RwTexture* >& textures, unsigned short usModelID, bool bDestroy = true, bool bKeepRaster = false, bool bRemoveRef = true ) = 0;
    virtual RwTexDictionary *   ReadTXD                     ( const char *szTXD ) = 0;
    virtual RpClump *           ReadDFF                     ( const char *szDFF, unsigned short usModelID ) = 0;
    virtual CColModel *         ReadCOL                     ( const char * szCOLFile ) = 0;
    virtual void                DestroyDFF                  ( RpClump * pClump ) = 0;
    virtual void                DestroyTXD                  ( RwTexDictionary * pTXD ) = 0;
    virtual void                DestroyTexture              ( RwTexture * pTex ) = 0;
    virtual void                ReplaceCollisions           ( CColModel * pColModel, unsigned short usModelID ) = 0;
    virtual bool                PositionFrontSeat           ( RpClump *pClump, unsigned short usModelID ) = 0;
    virtual unsigned int        LoadAtomics                 ( RpClump * pClump, RpAtomicContainer * pAtomics ) = 0;
    virtual void                ReplaceAllAtomicsInModel    ( RpClump * pSrc, unsigned short usModelID ) = 0;
    virtual void                ReplaceAllAtomicsInClump    ( RpClump * pDst, RpAtomicContainer * pAtomics, unsigned int uiAtomics ) = 0;
    virtual void                ReplaceWheels               ( RpClump * pClump, RpAtomicContainer * pAtomics, unsigned int uiAtomics, const char * szWheel ) = 0;
    virtual void                RepositionAtomic            ( RpClump * pDst, RpClump * pSrc, const char * szName ) = 0;
    virtual void                AddAllAtomics               ( RpClump * pDst, RpClump * pSrc ) = 0;
    virtual void                ReplaceVehicleModel         ( RpClump * pNew, unsigned short usModelID ) = 0;
    virtual void                ReplaceWeaponModel          ( RpClump * pNew, unsigned short usModelID ) = 0;
    virtual void                ReplacePedModel             ( RpClump * pNew, unsigned short usModelID ) = 0;
    virtual bool                ReplacePartModels           ( RpClump * pClump, RpAtomicContainer * pAtomics, unsigned int uiAtomics, const char * szName ) = 0;
    virtual void                InitWorldTextureWatch       ( PFN_WATCH_CALLBACK pfnWatchCallback ) = 0;
    virtual bool                AddWorldTextureWatch        ( CSHADERDUMMY* pShaderData, const char* strMatch, float fShaderPriority ) = 0;
    virtual void                RemoveWorldTextureWatch     ( CSHADERDUMMY* pShaderData, const char* strMatch ) = 0;
    virtual void                RemoveWorldTextureWatchByContext ( CSHADERDUMMY* pShaderData ) = 0;
    virtual void                PulseWorldTextureWatch      ( void ) = 0;
    virtual void                GetModelTextureNames        ( std::vector < SString >& outNameList, ushort usModelID ) = 0;
    virtual const SString&      GetTextureName              ( CD3DDUMMY* pD3DData ) = 0;
};

#endif
