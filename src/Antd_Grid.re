open Antd_Helpers;

[%bs.raw {|require("antd/lib/grid/style")|}];
module Row = {
  [@bs.module]
  external reactClass : ReasonReact.reactClass = "antd/lib/grid/row";

  [@bs.deriving jsConverter]
  type rowType = [ | `flex];

  [@bs.deriving jsConverter]
  type rowAlign = [ | `top | `middle | `bottom];

  [@bs.deriving jsConverter]
  type rowJustify = [
    | `start
    | [@bs.as "end"] `end_
    | `center
    | `spaceAround
    | `spaceBetween
  ];

  [@bs.obj] external _gutterBreakpointMap: 
    (
      ~xs: string=?,
      ~sm: string=?,
      ~md: string=?,
      ~lg: string=?,
      ~xl: string=?,
      ~xxl: string=?,
      unit
    ) => _ = "";

  let breakpointGutter = (~xs=?,~sm=?,~md=?,~lg=?,~xl=?,~xxl=?,()) => {
    /* ant design uses strings here even though it makes more sense to be number */
    _gutterBreakpointMap(
      ~xs  =? xs  |> Js.Option.map([@bs] (b => string_of_int(b))),
      ~sm  =? sm  |> Js.Option.map([@bs] (b => string_of_int(b))),
      ~md  =? md  |> Js.Option.map([@bs] (b => string_of_int(b))),
      ~lg  =? lg  |> Js.Option.map([@bs] (b => string_of_int(b))),
      ~xl  =? xl  |> Js.Option.map([@bs] (b => string_of_int(b))),
      ~xxl =? xxl |> Js.Option.map([@bs] (b => string_of_int(b))),
      ())
  };

  [@bs.obj]
  external makePropsGutter :
    (
      ~className: string=?,
      ~_type: string=?,
      ~align: string=?,
      ~justify: string=?,
      ~style: ReactDOMRe.Style.t=?,
      ~prefixCls: string=?,
      unit
    ) => _ = "";
    
  let make =
    (
      ~className=?,
      ~gutter=?,
      ~_type=?,
      ~align=?,
      ~justify=?,
      ~style=?,
      ~prefixCls=?,
      children
    ) => {
      let propsBase = makePropsGutter(
        ~className?, 
        ~_type=?Js.Option.map([@bs] (b => rowTypeToJs(b)), _type),
        ~align=?Js.Option.map([@bs] (b => rowAlignToJs(b)), align), 
        ~justify=?Js.Option.map([@bs] (b => rowJustifyToJs(b)), justify), 
        ~style?, 
        ~prefixCls?, 
        ());

      let props = propsBase |> addOptAnyProp("gutter",gutter);
  
      ReasonReact.wrapJsForReason(
        ~reactClass,
        ~props,
        children
      );
    };
};

module Col = {
  [@bs.module]
  external reactClass : ReasonReact.reactClass = "antd/lib/grid/col";

  [@bs.obj] external _colSizeMap: 
    (
      ~span: int=?,
      ~order: int=?,
      ~offset: int=?,
      ~push: int=?,
      ~pull: int=?,
      unit
    ) => _ = "";

  let complexColSize = (~span=?,~order=?,~offset=?,~push=?,~pull=?,())=> 
    _colSizeMap(
      ~span =? span, 
      ~order =? order, 
      ~offset =? offset, 
      ~push =? push, 
      ~pull =? pull, 
      ());

  [@bs.obj]
  external makePropsColBase:
    (
      ~className: string=?,
      ~span: int=?,
      ~order: int=?,
      ~offset: int=?,
      ~push: int=?,
      ~pull: int=?,
      ~prefixCls: string=?,
      ~style: ReactDOMRe.Style.t=?,
      unit
    ) =>
    _ =
    "";

  let make =
    (
      ~className=?,
      ~span=?,
      ~order=?,
      ~offset=?,
      ~push=?,
      ~pull=?,
      ~xs=?,
      ~sm=?,
      ~md=?,
      ~lg=?,
      ~xl=?,
      ~xxl=?,
      ~prefixCls=?,
      ~style=?,
      children
    ) => {
      let propsBase = makePropsColBase(
        ~className?,
        ~span?,
        ~order?,
        ~offset?,
        ~push?,
        ~pull?,
        ~prefixCls?,
        ~style?,
        ()
      );

      let props = propsBase |> addOptAnyProp("xs",xs) |> addOptAnyProp("sm",sm) |> addOptAnyProp("md",md) |> addOptAnyProp("lg",lg) |> addOptAnyProp("xl",xl) |> addOptAnyProp("xxl",xxl);

      ReasonReact.wrapJsForReason(
        ~reactClass,
        ~props,
        children
      );
    }
}