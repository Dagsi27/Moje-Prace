<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;

class IngredientList extends Model
{
    protected $fillable = ['user_id','product','done'];

    public function user(){
        return $this->belongsTo('App\Models\User');
    }
}
