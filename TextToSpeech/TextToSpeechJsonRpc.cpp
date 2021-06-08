/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2020 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "TextToSpeech.h"

namespace WPEFramework {
namespace Plugin {

    void TextToSpeech::RegisterAll()
    {
        registerMethod("enabletts", &TextToSpeech::Enable, this);
        registerMethod("listvoices", &TextToSpeech::ListVoices, this);
        registerMethod("setttsconfiguration", &TextToSpeech::SetConfiguration, this);
        registerMethod("getttsconfiguration", &TextToSpeech::GetConfiguration, this);
        registerMethod("isttsenabled", &TextToSpeech::IsEnabled, this);
        registerMethod("speak", &TextToSpeech::Speak, this);
        registerMethod("cancel", &TextToSpeech::Cancel, this);
        registerMethod("pause", &TextToSpeech::Pause, this);
        registerMethod("resume", &TextToSpeech::Resume, this);
        registerMethod("isspeaking", &TextToSpeech::IsSpeaking, this);
        registerMethod("getspeechstate", &TextToSpeech::GetSpeechState, this);
        registerMethod("updateACL", &TextToSpeech::UpdateACL, this);
        registerMethod("getapiversion", &TextToSpeech::getapiversion, this);
    }

  /*  bool TextToSpeech::CheckToken(const string& token, const string& method, const string& parameters)
    {
        TTSLOG_ERROR("vishnu1 .....token->%s  method->%s parameters->%s\n",token.c_str(),method.c_str(),parameters.c_str());
        if(m_RA && !method.compare("speak"))
         {
            std::string::size_type pos = token.find("://");
            std::string temp = token;
            if ( pos != string::npos) temp.erase(0,pos+3);
            if(temp.compare(m_callsign) != 0)
             {
                 return false;
             }

         }

        return true;
    } */

   /*  uint32_t TextToSpeech::UpdateACL(const JsonObject& parameters, JsonObject& response)
    {
            m_RA = true;
            string params, result;
            parameters.ToString(params);
            m_callMutex.lock();
            m_callsign.assign(parameters["callsign"].String());
            m_callMutex.unlock();
            response["callsign"] = parameters["callsign"].String();
            returnResponse(true);
    }
    */

    uint32_t TextToSpeech::Enable(const JsonObject& parameters, JsonObject& response)
    {
        if(_tts) {
            string params, result;
            parameters.ToString(params);
            uint32_t ret= _tts->Enable(params, result);
            response.FromString(result);
            return ret;
        }
        return Core::ERROR_NONE;
    }

    uint32_t TextToSpeech::ListVoices(const JsonObject& parameters, JsonObject& response)
    {
        if(_tts) {
            string params, result;
            parameters.ToString(params);
            uint32_t ret = _tts->ListVoices(params, result);
            response.FromString(result);
            return ret;
        }
        return Core::ERROR_NONE;
    }

    uint32_t TextToSpeech::SetConfiguration(const JsonObject& parameters, JsonObject& response)
    {
        if(_tts) {
            string params, result;
            parameters.ToString(params);
            uint32_t ret= _tts->SetConfiguration(params, result);
            response.FromString(result);
            return ret;
        }
        return Core::ERROR_NONE;
    }

    uint32_t TextToSpeech::GetConfiguration(const JsonObject& parameters, JsonObject& response)
    {
        if(_tts) {
            string result;
            uint32_t ret = _tts->GetConfiguration(result, result);
            response.FromString(result);
            return ret;
        }
        return Core::ERROR_NONE;
    }

    uint32_t TextToSpeech::IsEnabled(const JsonObject& parameters ,JsonObject& response)
    {
        if(_tts) {
            string result;
            uint32_t ret = _tts->IsEnabled(result, result);
            response.FromString(result);
            return ret;
        }
        return Core::ERROR_NONE;
    }

    uint32_t TextToSpeech::Speak(const JsonObject& parameters, JsonObject& response)
    {
        if(_tts) {
            string params, result;
            parameters.ToString(params);
            uint32_t ret= _tts->Speak(params, result);
            response.FromString(result);
            return ret;
        }
        return Core::ERROR_NONE;
    }

    uint32_t TextToSpeech::Cancel(const JsonObject& parameters, JsonObject& response)
    {
        if(_tts) {
            string params, result;
            parameters.ToString(params);
            uint32_t ret= _tts->Cancel(params, result);
            response.FromString(result);
            return ret;
        }
        return Core::ERROR_NONE;
    }


    uint32_t TextToSpeech::Pause(const JsonObject& parameters, JsonObject& response)
    {
        if(_tts) {
            string params, result;
            parameters.ToString(params);
            uint32_t ret= _tts->Pause(params, result);
            response.FromString(result);
            return ret;
        }
        return Core::ERROR_NONE;
    }

    uint32_t TextToSpeech::Resume(const JsonObject& parameters, JsonObject& response)
    {
        if(_tts) {
            string params, result;
            parameters.ToString(params);
            uint32_t ret= _tts->Resume(params, result);
            response.FromString(result);
            return ret;
        }
        return Core::ERROR_NONE;
    }

    uint32_t TextToSpeech::IsSpeaking(const JsonObject& parameters, JsonObject& response)
    {
        if(_tts) {
            string params, result;
            parameters.ToString(params);
            uint32_t ret = _tts->IsSpeaking(params, result);
            response.FromString(result);
            return ret;
        }
        return Core::ERROR_NONE;
    }

    uint32_t TextToSpeech::GetSpeechState(const JsonObject& parameters, JsonObject& response)
    {
        if(_tts) {
            string params, result;
            parameters.ToString(params);
            uint32_t ret = _tts->GetSpeechState(params, result);
            response.FromString(result);
            return ret;
        }
        return Core::ERROR_NONE;
    }

    uint32_t TextToSpeech::UpdateACL(const JsonObject& parameters, JsonObject& response)
    {
        if(_tts) {
            string params, result;
            parameters.ToString(params);
            uint32_t ret = _tts->UpdateACL(params, result);
            response.FromString(result);
            return ret;
        }
        return Core::ERROR_NONE;
    }
     bool TextToSpeech::CheckToken(const string& token, const string& method, const string& parameters)
    {
       TTSLOG_ERROR("vishnu0 jsonrpc .....token->%s  method->%s parameters->%s\n",token.c_str(),method.c_str(),parameters.c_str());
        if(_tts) {
            bool ret = _tts->CheckToken(token,method,parameters);
            return ret;
        }
        return Core::ERROR_NONE;
    }

    uint32_t TextToSpeech::getapiversion(const JsonObject& parameters, JsonObject& response)
    {
        UNUSED(parameters);

        response["version"] = _apiVersionNumber;

        returnResponse(true);
    }

    void TextToSpeech::dispatchJsonEvent(const char *event, const string &data)
    {
        TTSLOG_WARNING("Notify %s %s", event, data.c_str());
        JsonObject params;
        params.FromString(data);
        Notify(event, params);
    }

} // namespace Plugin
} // namespace WPEFramework
