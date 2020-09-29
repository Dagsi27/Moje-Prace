<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\User;
use Auth;

class AuthController extends Controller
{
    public function init(){
        $user = Auth::user();

        return response()->json(['user'=> $user],200);
    }

    public function login(Request $req){
        if(Auth::attempt(['email' => $req->email, 'password' => $req->password],true)){
            return response()->json(Auth::user(),200);
        }
        else{
            return response()->json(['error' => 'Could not log you in.'],401);
        }
    }

    public function register(Request $req){
        $user = User::where('email', $req->email)->first();


        if(isset($user->id)){

            return response()->json(['error'=>'Username already exists.'], 401);
        }
        
        $user = new User();

        $user->name = $req->name;
        $user->email = $req->email;
        $user->password = bcrypt($req->password);
        $user->save();

        Auth::login($user);

        return response()->json(Null, 200);
    }

    public function logout(Request $req){
        Auth::logout();
    }

}
