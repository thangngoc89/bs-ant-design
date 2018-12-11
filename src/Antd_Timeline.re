[@bs.module] external timeline: ReasonReact.reactClass = "antd/lib/timeline";

[%bs.raw {|require("antd/lib/timeline/style")|}];

module Item = {
  [@bs.val] external item: ReasonReact.reactClass = "Timeline.Item";

  [@bs.deriving abstract]
  type jsProps = {
    [@bs.optional]
    prefixCls: string,
    [@bs.optional]
    className: string,
    [@bs.optional]
    color: string,
    [@bs.optional]
    dot: ReasonReact.reactElement,
    [@bs.optional]
    pending: bool,
    [@bs.optional]
    style: ReactDOMRe.Style.t,
  };

  let make =
      (
        ~prefixCls=?,
        ~className=?,
        ~color=?,
        ~dot=?,
        ~pending=?,
        ~style=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=timeline,
      ~props=
        jsProps(
          ~prefixCls?,
          ~className?,
          ~color?,
          ~dot?,
          ~pending?,
          ~style?,
          (),
        ),
      children,
    );
};

[@bs.deriving jsConverter]
type mode = [ | `left | `alternate | `right];

[@bs.deriving abstract]
type jsProps = {
  [@bs.optional]
  prefixCls: string,
  [@bs.optional]
  className: string,
  [@bs.optional]
  pending: ReasonReact.reactElement,
  [@bs.optional]
  pendingDot: ReasonReact.reactElement,
  [@bs.optional]
  style: ReactDOMRe.Style.t,
  [@bs.optional]
  reverse: bool,
  [@bs.optional]
  mode,
};

let make =
    (
      ~prefixCls=?,
      ~className=?,
      ~pending=?,
      ~pendingDot=?,
      ~style=?,
      ~reverse=?,
      ~mode=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=timeline,
    ~props=
      jsProps(
        ~prefixCls?,
        ~className?,
        ~pending?,
        ~pendingDot?,
        ~style?,
        ~reverse?,
        ~mode?,
        (),
      ),
    children,
  );