/*
  ==============================================================================

  Copyright 2007-2013, 2017 Andi
  Copyright 2013-2016 Robert Taub

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice,
       this list of conditions and the following disclaimer.

    2. Redistributions in binary form must reproduce the above copyright notice,
       this list of conditions and the following disclaimer in the documentation
       and/or other materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE.

  ==============================================================================
*/

#define PRIM_COMPILE_INLINE
#include "prim.h"
using namespace prim;

static Value GetCommandLineSchema()
{
  Value Schema = Arguments::NewSchema("Arguments",
    "Demonstrates argument-parsing with prim",
    String("The prim argument-parser accepts parameters in the form:\n") +
    "-flag, --flag, -key=value, -key value, --key=value, and --key value.",
    "...");
  Arguments::AddParameter(Schema, "dryrun", Arguments::Flag,
    Arguments::Optional, "Optional flag", "Flags");
  Arguments::AddParameter(Schema, "mode", Arguments::Property,
    Arguments::Optional, "[fast, best]", "Flags");
  Arguments::AddParameter(Schema, "keywords", Arguments::PropertyList,
    Arguments::Optional, "Keywords", "Flags");
  Arguments::AddParameter(Schema, "in", Arguments::InputFile,
    Arguments::Required, "Input file", "Input/Output");
  Arguments::AddParameter(Schema, "out", Arguments::OutputFile,
    Arguments::Optional, "Output file", "Input/Output");
  return Schema;
}

int main(int argc, const char** argv)
{
  if(Value Arguments = Arguments::Process(argc, argv, GetCommandLineSchema()))
    C::Out() >> JSON::Export(Arguments);
  return AutoRelease<Console>();
}
