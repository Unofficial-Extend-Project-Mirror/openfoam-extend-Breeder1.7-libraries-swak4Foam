/*---------------------------------------------------------------------------*\
 ##   ####  ######     |
 ##  ##     ##         | Copyright: ICE Stroemungsfoschungs GmbH
 ##  ##     ####       |
 ##  ##     ##         | http://www.ice-sf.at
 ##   ####  ######     |
-------------------------------------------------------------------------------
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright  held by original author
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is based on OpenFOAM.

    OpenFOAM is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM; if not, write to the Free Software Foundation,
    Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

Class
    foreignMeshesFollowTime

Description
    Function object that makes a number of foreign meshes "follow" the
    current time

SourceFiles
    foreignMeshesFollowTime.C

Contributors/Copyright:
    2012-2014 Bernhard F.W. Gschaider <bgschaid@ice-sf.at>
    2013 Bruno Santos <wyldckat@gmail.com>

 SWAK Revision: $Id:  $ 
\*---------------------------------------------------------------------------*/

#ifndef foreignMeshesFollowTime_H
#define foreignMeshesFollowTime_H

#include "primitiveFieldsFwd.H"
#include "pointFieldFwd.H"

namespace Foam
{
// Forward declaration of classes
class dictionary;
class objectRegistry;
class mapPolyMesh;

class foreignMeshesFollowTime
{
    //- Disallow default bitwise copy construct
    foreignMeshesFollowTime(const foreignMeshesFollowTime&);

    //- Disallow default bitwise assignment
    void operator=(const foreignMeshesFollowTime&);

    //- names of the meshes that should be followed
    wordList followingMeshes_;

    //- do the actual work
    void followCurrentTime();

    //- object registry
    const objectRegistry &obr_;

public:

    //- Runtime type information
    TypeName("foreignMeshesFollowTime");


    // Constructors

    //- Construct for given objectRegistry and dictionary.
    //  Allow the possibility to load fields from files
    foreignMeshesFollowTime
    (
        const word& name,
        const objectRegistry&,
        const dictionary&,
        const bool loadFromFiles = false
    );


    //- Destructor
    virtual ~foreignMeshesFollowTime();


    // Member Functions

    //- Read the forces data
    virtual void read(const dictionary&);

    //- Execute, currently does nothing
    virtual void execute();

    //- Execute at the final time-loop, currently does nothing
    virtual void end();

    //- Write the forces
    virtual void write();

    //- Update for changes of mesh
    virtual void updateMesh(const mapPolyMesh&)
        {}

    //- Update for changes of mesh
    virtual void movePoints(const pointField&)
        {}

    //- Clear all data
    void clearData();
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif
