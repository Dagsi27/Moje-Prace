<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\IngredientList;
use Auth;
use Log;


class IngredientListController extends Controller
{
    public function index(){
        $user = Auth::user();
        $list = IngredientList::where('user_id',$user->id)->get();
        return $list;
    }

    public function store(Request $req) {
        $user = Auth::user();
        $list = new IngredientList;
        
        $list->user_id = $user->id;
        $list->product = $req->product;
        $list->done = $req->done;

        $list->save();

        return response()->json(null, 200);
    }

    public function update(Request $req){
        $list = IngredientList::where('id',$req->id)->first();

        $list->product= $req->product;
        $list->done = $req->done;

        $list->save();

        return response()->json(null,200);
    }

    public function delete(Request $req){
        $list = IngredientList::where('id',$req->id)->first();

        $list->delete();

        return response()->json(null, 200);
    }
}
